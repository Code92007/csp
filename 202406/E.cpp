#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
struct Rect {
    int xl, xr, yl, yr, value;
};
vector<Rect> rectangles;
// Static upper envelope of weighted closed intervals, with range maximum queries.
struct Envelope {
    vector<int> coordinates, maximum;
    int base = 0;
    void build(vector<int> ids) {
        if (ids.empty())
            return;
        if (ids.size() <= 8) {
            coordinates = std::move(ids);
            base = -1;
            return;
        }
        // IDs arrive in decreasing value order. Paint only uncovered positions.
        struct Piece {
            int l, r, value;
        };
        vector<Piece> pieces;
        map<int, int> covered;
        for (int id : ids) {
            auto rect = rectangles[id];
            int l = rect.yl, r = rect.yr;
            auto it = covered.upper_bound(l);
            if (it != covered.begin()) {
                auto previous = prev(it);
                if (previous->second >= l - 1) {
                    if (previous->second >= r)
                        continue;
                    it = previous;
                }
            }
            int begin = l, end = r, cursor = l;
            while (it != covered.end() && it->first <= r + 1) {
                if (cursor < it->first && cursor <= r)
                    pieces.push_back({cursor, min(r, it->first - 1), rect.value});
                cursor = max(cursor, it->second + 1);
                begin = min(begin, it->first);
                end = max(end, it->second);
                it = covered.erase(it);
            }
            if (cursor <= r)
                pieces.push_back({cursor, r, rect.value});
            covered.emplace(begin, end);
        }
        sort(pieces.begin(), pieces.end(), [](Piece a, Piece b) { return a.l < b.l; });
        vector<int> values;
        for (auto p : pieces) {
            if (!coordinates.empty() && coordinates.back() == p.l)
                values.back() = p.value;
            else {
                coordinates.push_back(p.l);
                values.push_back(p.value);
            }
            coordinates.push_back(p.r + 1);
            values.push_back(0);
        }
        base = coordinates.size();
        maximum.assign(2 * base, 0);
        copy(values.begin(), values.end(), maximum.begin() + base);
        for (int i = base - 1; i; --i)
            maximum[i] = max(maximum[2 * i], maximum[2 * i + 1]);
    }
    int query(int l, int r) const {
        if (base == -1) {
            int ans = 0;
            for (int id : coordinates) {
                auto a = rectangles[id];
                if (a.yl <= r && a.yr >= l)
                    ans = max(ans, a.value);
            }
            return ans;
        }
        if (!base || r < coordinates.front())
            return 0;
        int a = max(
            0,
            int(upper_bound(coordinates.begin(), coordinates.end(), l) - coordinates.begin()) - 1);
        int b = int(upper_bound(coordinates.begin(), coordinates.end(), r) - coordinates.begin());
        int ans = 0;
        for (a += base, b += base; a < b; a >>= 1, b >>= 1) {
            if (a & 1)
                ans = max(ans, maximum[a++]);
            if (b & 1)
                ans = max(ans, maximum[--b]);
        }
        return ans;
    }
};
struct Node {
    vector<int> allIds, coverIds;
    Envelope all, cover;
    int bound = 0;
    bool same = false;
};
vector<Node> tree;
void add(int u, int l, int r, int id) {
    const auto &a = rectangles[id];
    tree[u].allIds.push_back(id);
    if (a.xl <= l && r <= a.xr) {
        tree[u].coverIds.push_back(id);
        return;
    }
    int mid = (l + r) / 2;
    if (a.xl <= mid)
        add(u + 1, l, mid, id);
    if (a.xr > mid)
        add(u + 2 * (mid - l + 1), mid + 1, r, id);
}
int query(int u, int l, int r, int a, int b, int c, int d, int known = 0) {
    if (tree[u].bound <= known)
        return known;
    if (a <= l && r <= b)
        return max(known, (tree[u].same ? tree[u].cover : tree[u].all).query(c, d));
    int ans = tree[u].cover.query(c, d), mid = (l + r) / 2;
    ans = max(ans, known);
    if (a <= mid)
        ans = max(ans, query(u + 1, l, mid, a, b, c, d, ans));
    if (b > mid)
        ans = max(ans, query(u + 2 * (mid - l + 1), mid + 1, r, a, b, c, d, ans));
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    rectangles.resize(n);
    tree.resize(2 * n + 2);
    for (auto &r : rectangles)
        cin >> r.xl >> r.xr >> r.yl >> r.yr >> r.value;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [](int a, int b) { return rectangles[a].value > rectangles[b].value; });
    for (int i : order)
        add(1, 1, n, i);
    for (auto &node : tree) {
        node.bound = node.allIds.empty() ? 0 : rectangles[node.allIds[0]].value;
        node.same = node.allIds == node.coverIds;
        if (!node.same)
            node.all.build(std::move(node.allIds));
        else
            vector<int>().swap(node.allIds);
        node.cover.build(std::move(node.coverIds));
    }
    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << query(1, 1, n, a, b, c, d) << '\n';
    }
}
