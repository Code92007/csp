#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    vector<vector<int>> tree(2 * n + 1);
    vector<int> dfn(n + 1), low(n + 1), par(n + 1), pe(n + 1, -1), pos(n + 1), vertices, dfs;
    int clock = 0, N = n;
    dfn[1] = low[1] = ++clock;
    dfs.push_back(1);
    vertices.push_back(1);
    // Explicit DFS stack avoids recursion overflow on a long chain.
    while (!dfs.empty()) {
        int u = dfs.back();
        if (pos[u] < int(g[u].size())) {
            auto [v, id] = g[u][pos[u]++];
            if (id == pe[u])
                continue;
            if (!dfn[v]) {
                par[v] = u;
                pe[v] = id;
                dfn[v] = low[v] = ++clock;
                vertices.push_back(v);
                dfs.push_back(v);
            } else
                low[u] = min(low[u], dfn[v]);
        } else {
            dfs.pop_back();
            int p = par[u];
            if (!p)
                continue;
            low[p] = min(low[p], low[u]);
            if (low[u] >= dfn[p]) {
                ++N;
                tree[N].push_back(p);
                tree[p].push_back(N);
                int v;
                do {
                    v = vertices.back();
                    vertices.pop_back();
                    tree[N].push_back(v);
                    tree[v].push_back(N);
                } while (v != u);
            }
        }
    }
    int LOG = 1;
    while ((1 << LOG) <= N)
        ++LOG;
    vector<vector<int>> up(LOG, vector<int>(N + 1));
    vector<int> tin(N + 1), tout(N + 1), dep(N + 1), prefix(N + 1), order{1};
    vector<pair<int, bool>> st{{1, false}};
    clock = 0;
    while (!st.empty()) {
        auto [u, exit] = st.back();
        st.pop_back();
        if (exit) {
            tout[u] = clock;
            continue;
        }
        tin[u] = ++clock;
        prefix[u] = prefix[up[0][u]] + (u <= n);
        for (int j = 1; j < LOG; ++j)
            up[j][u] = up[j - 1][up[j - 1][u]];
        st.push_back({u, true});
        for (int v : tree[u])
            if (v != up[0][u]) {
                up[0][v] = u;
                dep[v] = dep[u] + 1;
                st.push_back({v, false});
            }
    }
    auto ancestor = [&](int u, int v) { return tin[u] <= tin[v] && tout[v] <= tout[u]; };
    auto lca = [&](int u, int v) {
        if (ancestor(u, v))
            return u;
        if (ancestor(v, u))
            return v;
        for (int j = LOG - 1; j >= 0; --j)
            if (up[j][u] && !ancestor(up[j][u], v))
                u = up[j][u];
        return up[0][u];
    };
    vector<int> marked(N + 1), sub(N + 1), maxBranch(N + 1), vp(N + 1);
    for (int qi = 1; qi <= q; ++qi) {
        int c;
        cin >> c;
        vector<int> v(c);
        for (int &x : v) {
            cin >> x;
            marked[x] = qi;
        }
        auto cmp = [&](int a, int b) { return tin[a] < tin[b]; };
        sort(v.begin(), v.end(), cmp);
        for (int i = 1; i < c; ++i)
            v.push_back(lca(v[i - 1], v[i]));
        v.push_back(1);
        sort(v.begin(), v.end(), cmp);
        v.erase(unique(v.begin(), v.end()), v.end());
        vector<int> stack;
        for (int u : v) {
            sub[u] = (marked[u] == qi);
            maxBranch[u] = 0;
            while (!stack.empty() && !ancestor(stack.back(), u))
                stack.pop_back();
            vp[u] = stack.empty() ? 0 : stack.back();
            stack.push_back(u);
        }
        long long ans = 1LL * (n - 1) * c; // baseline c - [marked]
        for (int i = int(v.size()) - 1; i >= 0; --i) {
            int u = v[i], p = vp[u];
            int best = max(maxBranch[u], c - sub[u]);
            if (u <= n)
                ans += best - (c - (marked[u] == qi));
            if (p) {
                int middle = prefix[u] - prefix[p] - (u <= n);
                ans -= 1LL * middle * min(sub[u], c - sub[u]);
                sub[p] += sub[u];
                maxBranch[p] = max(maxBranch[p], sub[u]);
            }
        }
        cout << ans << '\n';
    }
}
