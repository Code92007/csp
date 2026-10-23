#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }
    int odd = 0;
    for (int u = 1; u <= n; ++u) {
        sort(graph[u].begin(), graph[u].end());
        odd += graph[u].size() % 2;
    }
    if (odd != 0 && (odd != 2 || graph[1].size() % 2 == 0)) {
        cout << -1 << '\n';
        return 0;
    }
    vector<bool> used(m);
    vector<int> pointer(n + 1), stack{1}, path;
    while (!stack.empty()) {
        int u = stack.back();
        auto &i = pointer[u];
        while (i < int(graph[u].size()) && used[graph[u][i].second])
            ++i;
        if (i == int(graph[u].size())) {
            path.push_back(u);
            stack.pop_back();
        } else {
            auto [v, id] = graph[u][i++];
            used[id] = true;
            stack.push_back(v);
        }
    }
    if (path.size() != size_t(m + 1)) {
        cout << -1 << '\n';
        return 0;
    }
    reverse(path.begin(), path.end());
    for (size_t i = 0; i < path.size(); ++i)
        cout << path[i] << (i + 1 == path.size() ? '\n' : ' ');
}
