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
    vector<vector<int>> graph(n + m);
    for (int u = 1; u < n + m; ++u) {
        int p;
        cin >> p;
        --p;
        graph[u].push_back(p);
        graph[p].push_back(u);
    }
    auto farthest = [&](int start) {
        vector<int> distance(n + m, -1), queue{start};
        distance[start] = 0;
        for (size_t i = 0; i < queue.size(); ++i)
            for (int v : graph[queue[i]])
                if (distance[v] < 0) {
                    distance[v] = distance[queue[i]] + 1;
                    queue.push_back(v);
                }
        int u = max_element(distance.begin(), distance.end()) - distance.begin();
        return pair<int, int>{u, distance[u]};
    };
    auto [endpoint, unused] = farthest(0);
    cout << farthest(endpoint).second << '\n';
}
