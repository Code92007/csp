#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <vector>
using namespace std;
using i64 = long long;
using Matrix = vector<vector<i64>>;
const i64 INF = 4000000000000000000LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<i64>> cost(n, vector<i64>(k));
    for (auto &row : cost)
        for (auto &x : row)
            cin >> x;
    vector<map<int, Matrix>> edges(n);
    auto connect = [&](int u, int v, const Matrix &a) {
        Matrix transpose(k, vector<i64>(k));
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                transpose[j][i] = a[i][j];
        edges[u][v] = a;
        edges[v][u] = transpose;
    };
    for (int e = 0; e < m; ++e) {
        int u, v;
        cin >> u >> v;
        Matrix a(k, vector<i64>(k));
        for (auto &row : a)
            for (auto &x : row)
                cin >> x;
        connect(u, v, a);
    }
    // Count components after deleting each vertex using an iterative low-link DFS.
    vector<int> tin(n), low(n), parent(n, -1), children(n), separated(n), order;
    int timer = 0;
    vector<map<int, Matrix>::iterator> cursor(n);
    vector<int> stack{0};
    tin[0] = low[0] = ++timer;
    cursor[0] = edges[0].begin();
    while (!stack.empty()) {
        int u = stack.back();
        if (cursor[u] == edges[u].end()) {
            stack.pop_back();
            order.push_back(u);
            if (parent[u] != -1) {
                int p = parent[u];
                low[p] = min(low[p], low[u]);
                if (low[u] >= tin[p])
                    ++separated[p];
            }
            continue;
        }
        int v = (cursor[u]++)->first;
        if (v == parent[u])
            continue;
        if (tin[v])
            low[u] = min(low[u], tin[v]);
        else {
            parent[v] = u;
            ++children[u];
            tin[v] = low[v] = ++timer;
            cursor[v] = edges[v].begin();
            stack.push_back(v);
        }
    }
    int fixed = -1;
    for (int u = 0; u < n; ++u) {
        int components = parent[u] == -1 ? children[u] : separated[u] + 1;
        if (m - n + 1 - int(edges[u].size()) + components == 0) {
            fixed = u;
            break;
        }
    }
    if (fixed != -1) {
        // After fixing this vertex, all remaining components are trees.
        vector<int> par(n, -2), traversal;
        par[fixed] = -1;
        for (int start = 0; start < n; ++start)
            if (par[start] == -2) {
                par[start] = -1;
                traversal.push_back(start);
                for (size_t head = traversal.size() - 1; head < traversal.size(); ++head) {
                    int u = traversal[head];
                    for (const auto &[v, a] : edges[u])
                        if (par[v] == -2) {
                            par[v] = u;
                            traversal.push_back(v);
                        }
                }
            }
        i64 answer = INF;
        for (int label = 0; label < k; ++label) {
            auto dp = cost;
            for (const auto &[u, a] : edges[fixed])
                for (int b = 0; b < k; ++b)
                    dp[u][b] += a[label][b];
            i64 total = cost[fixed][label];
            for (auto it = traversal.rbegin(); it != traversal.rend(); ++it) {
                int u = *it, p = par[u];
                if (p == -1) {
                    total += *min_element(dp[u].begin(), dp[u].end());
                    continue;
                }
                const auto &a = edges[p].at(u);
                for (int x = 0; x < k; ++x) {
                    i64 best = INF;
                    for (int y = 0; y < k; ++y)
                        best = min(best, a[x][y] + dp[u][y]);
                    dp[p][x] += best;
                }
            }
            answer = min(answer, total);
        }
        cout << answer << '\n';
        return 0;
    }
    // Eliminate vertices of degree <= 2, keeping exact unary/pairwise costs.
    queue<int> ready;
    vector<bool> removed(n);
    for (int u = 0; u < n; ++u)
        if (edges[u].size() <= 2)
            ready.push(u);
    i64 constant = 0;
    while (!ready.empty()) {
        int u = ready.front();
        ready.pop();
        if (removed[u] || edges[u].size() > 2)
            continue;
        removed[u] = true;
        if (edges[u].empty()) {
            constant += *min_element(cost[u].begin(), cost[u].end());
            continue;
        }
        int v = edges[u].begin()->first;
        if (edges[u].size() == 1) {
            const auto &a = edges[v].at(u);
            for (int x = 0; x < k; ++x) {
                i64 best = INF;
                for (int y = 0; y < k; ++y)
                    best = min(best, a[x][y] + cost[u][y]);
                cost[v][x] += best;
            }
            edges[v].erase(u);
            ready.push(v);
        } else {
            int w = next(edges[u].begin())->first;
            const auto &a = edges[v].at(u);
            const auto &b = edges[u].at(w);
            Matrix merged(k, vector<i64>(k, INF));
            for (int x = 0; x < k; ++x)
                for (int y = 0; y < k; ++y) {
                    for (int z = 0; z < k; ++z)
                        merged[x][y] = min(merged[x][y], a[x][z] + cost[u][z] + b[z][y]);
                    if (edges[v].count(w))
                        merged[x][y] += edges[v].at(w)[x][y];
                }
            edges[v].erase(u);
            edges[w].erase(u);
            connect(v, w, merged);
            ready.push(v);
            ready.push(w);
        }
        edges[u].clear();
    }
    vector<int> core;
    for (int u = 0; u < n; ++u)
        if (!removed[u])
            core.push_back(u);
    vector<int> label(n);
    i64 answer = INF;
    function<void(int, i64)> enumerate = [&](int index, i64 value) {
        if (value >= answer)
            return;
        if (index == int(core.size())) {
            answer = value;
            return;
        }
        int u = core[index];
        for (int x = 0; x < k; ++x) {
            i64 next_value = value + cost[u][x];
            for (int j = 0; j < index; ++j)
                if (edges[u].count(core[j]))
                    next_value += edges[u].at(core[j])[x][label[core[j]]];
            label[u] = x;
            enumerate(index + 1, next_value);
        }
    };
    enumerate(0, constant);
    cout << answer << '\n';
}
