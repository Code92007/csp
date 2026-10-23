#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <random>
#include <utility>
#include <vector>
using namespace std;
struct Fenwick {
    int n;
    vector<int> t;
    explicit Fenwick(int n) : n(n), t(n + 1) {}
    void add(int x, int v) {
        for (; x <= n; x += x & -x)
            t[x] += v;
    }
    int sum(int x) {
        int s = 0;
        for (; x; x -= x & -x)
            s += t[x];
        return s;
    }
    int kth(int k) {
        int x = 0;
        for (int p = 1 << 17; p; p >>= 1)
            if (x + p <= n && t[x + p] < k) {
                k -= t[x + p];
                x += p;
            }
        return x + 1;
    }
};
struct Segment {
    int u, v, version = 0;
    bool done = false;
    vector<int> users;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, X;
    cin >> n >> X;
    vector<vector<int>> g(n + 1);
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> par(n + 1), depth(n + 1), size(n + 1, 1), heavy(n + 1), top(n + 1), tin(n + 1),
        at(n + 1), order{1};
    for (size_t i = 0; i < order.size(); ++i) {
        int u = order[i];
        for (int v : g[u])
            if (v != par[u]) {
                par[v] = u;
                depth[v] = depth[u] + 1;
                order.push_back(v);
            }
    }
    for (int i = n - 1; i > 0; --i) {
        int u = order[i], p = par[u];
        size[p] += size[u];
        if (size[u] > size[heavy[p]] || !heavy[p])
            heavy[p] = u;
    }
    int timer = 0;
    vector<pair<int, int>> stack{{1, 1}};
    while (!stack.empty()) {
        auto [u, h] = stack.back();
        stack.pop_back();
        for (; u; u = heavy[u]) {
            top[u] = h;
            tin[u] = ++timer;
            at[timer] = u;
            for (int v : g[u])
                if (par[v] == u && v != heavy[u])
                    stack.push_back({v, v});
        }
    }
    auto lca = [&](int u, int v) {
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            u = par[top[u]];
        }
        return depth[u] < depth[v] ? u : v;
    };
    auto distance = [&](int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; };
    int k;
    cin >> k;
    vector<int> stations(k);
    for (int &u : stations)
        cin >> u;
    int m;
    cin >> m;
    vector<int> missing(m);
    vector<Segment> segments;
    map<pair<int, int>, int> ids;
    for (int plan = 0; plan < m; ++plan) {
        int s, t;
        cin >> s >> t;
        int length = distance(s, t);
        vector<pair<int, int>> points{{0, s}, {length, t}};
        for (int u : stations) {
            int d = distance(s, u);
            if (d + distance(u, t) == length)
                points.push_back({d, u});
        }
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        for (size_t i = 1; i < points.size(); ++i) {
            if (points[i].first - points[i - 1].first <= 1)
                continue;
            int u = points[i - 1].second, v = points[i].second;
            if (u > v)
                swap(u, v);
            auto [it, newKey] = ids.emplace(make_pair(u, v), int(segments.size()));
            if (newKey)
                segments.push_back({u, v, 0, false, {}});
            segments[it->second].users.push_back(plan);
            ++missing[plan];
        }
    }
    int answer = count(missing.begin(), missing.end(), 0);
    Fenwick bit(n);
    for (int u = 2; u <= n; ++u)
        bit.add(tin[u], 1);
    vector<vector<pair<int, int>>> watch(n + 1);
    mt19937 rng(random_device{}()); // random choices change running time only, never answers
    auto refresh = [&](int id) {
        auto &s = segments[id];
        ++s.version;
        vector<pair<int, int>> pieces;
        int u = s.u, v = s.v, total = 0;
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]])
                swap(u, v);
            pieces.push_back({tin[top[u]], tin[u]});
            u = par[top[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        if (u != v)
            pieces.push_back({tin[u] + 1, tin[v]});
        vector<int> counts;
        for (auto [l, r] : pieces) {
            int c = bit.sum(r) - bit.sum(l - 1);
            counts.push_back(c);
            total += c;
        }
        if (total <= 1) {
            s.done = true;
            for (int plan : s.users)
                if (--missing[plan] == 0)
                    ++answer;
            return;
        }
        int first = uniform_int_distribution<int>(1, total)(rng);
        int second = uniform_int_distribution<int>(1, total - 1)(rng);
        if (second >= first)
            ++second;
        for (int rank : {first, second}) {
            for (size_t i = 0; i < pieces.size(); ++i) {
                if (rank > counts[i])
                    rank -= counts[i];
                else {
                    int pos = bit.kth(bit.sum(pieces[i].first - 1) + rank);
                    watch[at[pos]].push_back({id, s.version});
                    break;
                }
            }
        }
    };
    for (int i = 0; i < int(segments.size()); ++i)
        refresh(i);
    int q, last = 0;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 2) {
            cout << answer << '\n';
            last = answer;
        } else {
            int u, v;
            cin >> u >> v;
            u ^= X * last;
            v ^= X * last;
            if (depth[u] < depth[v])
                swap(u, v);
            bit.add(tin[u], -1);
            auto events = std::move(watch[u]);
            for (auto [id, version] : events)
                if (!segments[id].done && segments[id].version == version)
                    refresh(id);
        }
    }
}
