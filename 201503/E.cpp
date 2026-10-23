#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const int LOG = 18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> price(n + 1);
    price[0] = 2000000000;
    for (int i = 1; i <= n; ++i)
        cin >> price[i];
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<pair<int, int>> queries(m);
    for (auto &q : queries)
        cin >> q.first >> q.second;
    vector<ll> answer(m), distance(n + 1), upCost(n + 1), downCost(n + 1);
    vector<int> parent(n + 1), size(n + 1), branch(n + 1), prefixMin(n + 1);
    vector<bool> removed(n + 1);
    vector<array<int, LOG>> up(n + 1), minimum(n + 1);
    minimum[0].fill(price[0]);
    struct Task {
        int start;
        vector<int> ids;
    };
    vector<Task> tasks(1);
    tasks[0].start = 1;
    tasks[0].ids.resize(m);
    iota(tasks[0].ids.begin(), tasks[0].ids.end(), 0);
    while (!tasks.empty()) {
        Task task = std::move(tasks.back());
        tasks.pop_back();
        if (task.ids.empty())
            continue;
        vector<int> order{task.start};
        parent[task.start] = 0;
        for (size_t i = 0; i < order.size(); ++i) {
            int u = order[i];
            for (auto [v, w] : g[u])
                if (!removed[v] && v != parent[u]) {
                    parent[v] = u;
                    order.push_back(v);
                }
        }
        int total = order.size(), center = task.start;
        for (auto it = order.rbegin(); it != order.rend(); ++it) {
            int u = *it;
            size[u] = 1;
            int largest = 0;
            for (auto [v, w] : g[u])
                if (!removed[v] && parent[v] == u) {
                    size[u] += size[v];
                    largest = max(largest, size[v]);
                }
            if (max(largest, total - size[u]) <= total / 2)
                center = u;
        }
        order = {center};
        parent[center] = 0;
        branch[center] = -1;
        distance[center] = upCost[center] = downCost[center] = 0;
        prefixMin[center] = price[center];
        vector<int> roots;
        for (auto [v, w] : g[center])
            if (!removed[v])
                roots.push_back(v);
        for (size_t i = 0; i < order.size(); ++i) {
            int u = order[i], p = parent[u];
            up[u][0] = p;
            minimum[u][0] = price[p];
            for (int j = 1; j < LOG; ++j) {
                up[u][j] = up[up[u][j - 1]][j - 1];
                minimum[u][j] = min(minimum[u][j - 1], minimum[up[u][j - 1]][j - 1]);
            }
            if (p) {
                int v = u;
                for (int j = LOG - 1; j >= 0; --j)
                    if (up[v][j] && minimum[v][j] >= price[u])
                        v = up[v][j];
                int lower = parent[v];
                upCost[u] = ll(price[u]) * (distance[u] - distance[lower]) + upCost[lower];
            }
            int rootIndex = 0;
            for (auto [v, w] : g[u])
                if (!removed[v] && v != p) {
                    parent[v] = u;
                    distance[v] = distance[u] + w;
                    prefixMin[v] = min(prefixMin[u], price[v]);
                    downCost[v] = downCost[u] + ll(w) * prefixMin[u];
                    branch[v] = u == center ? rootIndex++ : branch[u];
                    order.push_back(v);
                }
        }
        vector<vector<int>> pending(roots.size());
        for (int id : task.ids) {
            auto [s, t] = queries[id];
            if (s != center && t != center && branch[s] == branch[t]) {
                pending[branch[s]].push_back(id);
                continue;
            }
            ll cost = upCost[s];
            int p = prefixMin[s];
            if (prefixMin[t] >= p)
                cost += ll(p) * distance[t];
            else {
                int v = t;
                for (int j = LOG - 1; j >= 0; --j)
                    if (up[v][j] && prefixMin[up[v][j]] < p)
                        v = up[v][j];
                cost += ll(p) * distance[v] + downCost[t] - downCost[v];
            }
            answer[id] = cost;
        }
        removed[center] = true;
        for (size_t i = 0; i < roots.size(); ++i)
            if (!pending[i].empty())
                tasks.push_back({roots[i], std::move(pending[i])});
    }
    for (ll x : answer)
        cout << x << '\n';
}
