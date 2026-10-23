#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using Int = __int128_t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector<int> parent(n + 1), root(n + 1);
        vector<ll> depth(n + 1), value(n + 1), ideal(n + 1), xs;
        vector<Int> dp(n + 1);
        vector<vector<int>> lines(n + 1);
        for (int i = 1; i <= n; ++i) {
            ll length;
            cin >> parent[i] >> length >> value[i] >> ideal[i];
            depth[i] = depth[parent[i]] + length;
            xs.push_back(depth[i] + ideal[i]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        struct Node {
            int line = 0, left = 0, right = 0;
        };
        vector<Node> tree(1);
        auto eval = [&](int i, ll x) {
            return Int(2) * depth[i] * x + dp[i] - Int(depth[i]) * depth[i];
        };
        function<int(int, int, int, int)> insert = [&](int u, int line, int lo, int hi) {
            if (!u) {
                tree.push_back({line, 0, 0});
                return int(tree.size()) - 1;
            }
            int mid = (lo + hi) / 2;
            if (eval(line, xs[mid]) > eval(tree[u].line, xs[mid]))
                swap(line, tree[u].line);
            if (lo == hi)
                return u;
            if (eval(line, xs[lo]) > eval(tree[u].line, xs[lo])) {
                int child = insert(tree[u].left, line, lo, mid);
                tree[u].left = child;
            } else if (eval(line, xs[hi]) > eval(tree[u].line, xs[hi])) {
                int child = insert(tree[u].right, line, mid + 1, hi);
                tree[u].right = child;
            }
            return u;
        };
        auto query = [&](int u, ll x) {
            int lo = 0, hi = xs.size() - 1;
            Int best = -(Int(1) << 120);
            while (u) {
                best = max(best, eval(tree[u].line, x));
                int mid = (lo + hi) / 2;
                if (x <= xs[mid]) {
                    hi = mid;
                    u = tree[u].left;
                } else {
                    lo = mid + 1;
                    u = tree[u].right;
                }
            }
            return best;
        };
        ll answer = 0;
        const ll MOD = 1000000000000000000LL;
        for (int u = n; u >= 1; --u) {
            ll x = depth[u] + ideal[u];
            if (root[u])
                dp[u] = max(Int(0), query(root[u], x) - Int(x) * x + value[u]);
            answer = (answer + ll(dp[u] % MOD)) % MOD;
            root[u] = insert(root[u], u, 0, xs.size() - 1);
            lines[u].push_back(u);
            int p = parent[u];
            if (!p)
                continue;
            if (lines[p].size() < lines[u].size()) {
                swap(lines[p], lines[u]);
                swap(root[p], root[u]);
            }
            for (int line : lines[u]) {
                root[p] = insert(root[p], line, 0, xs.size() - 1);
                lines[p].push_back(line);
            }
            vector<int>().swap(lines[u]);
        }
        cout << answer << '\n';
    }
}
