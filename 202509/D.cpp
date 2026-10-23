#include <array>
#include <iostream>
#include <vector>
using namespace std;
constexpr int LOG = 20;
struct Node {
    int left = 0, right = 0, count = 0;
};
vector<Node> seg(1);
int insert(int old, int l, int r, int x) {
    int u = seg.size();
    seg.push_back(seg[old]);
    ++seg[u].count;
    if (l < r) {
        int mid = (l + r) / 2;
        if (x <= mid)
            seg[u].left = insert(seg[old].left, l, mid, x);
        else
            seg[u].right = insert(seg[old].right, mid + 1, r, x);
    }
    return u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), root(n + 1), depth(n + 1);
    vector<array<int, LOG>> up(n + 1);
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    seg.reserve(size_t(n) * (LOG + 1));
    vector<int> order{1};
    for (size_t i = 0; i < order.size(); ++i) {
        int u = order[i];
        root[u] = insert(root[up[u][0]], 0, n, a[u]);
        for (int j = 1; j < LOG; ++j)
            up[u][j] = up[up[u][j - 1]][j - 1];
        for (int v : graph[u]) {
            if (v == up[u][0])
                continue;
            up[v][0] = u;
            depth[v] = depth[u] + 1;
            order.push_back(v);
        }
    }
    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);
        int difference = depth[u] - depth[v];
        for (int j = 0; j < LOG; ++j)
            if (difference >> j & 1)
                u = up[u][j];
        if (u == v)
            return u;
        for (int j = LOG - 1; j >= 0; --j)
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        return up[u][0];
    };
    while (m--) {
        int u, v;
        cin >> u >> v;
        int w = lca(u, v);
        array<int, 4> roots{root[u], root[v], root[w], root[up[w][0]]};
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            int count = seg[seg[roots[0]].left].count + seg[seg[roots[1]].left].count -
                        seg[seg[roots[2]].left].count - seg[seg[roots[3]].left].count;
            bool full = count == mid - l + 1;
            for (int &rt : roots)
                rt = full ? seg[rt].right : seg[rt].left;
            if (full)
                l = mid + 1;
            else
                r = mid;
        }
        cout << l << '\n';
    }
}
