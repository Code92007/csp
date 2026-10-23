#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n), reverse(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        reverse[v].push_back(u);
    }
    vector<bool> seen(n);
    vector<int> order;
    for (int start = 0; start < n; ++start)
        if (!seen[start]) {
            vector<pair<int, size_t>> stack{{start, 0}};
            seen[start] = true;
            while (!stack.empty()) {
                int u = stack.back().first;
                auto &index = stack.back().second;
                if (index == graph[u].size()) {
                    order.push_back(u);
                    stack.pop_back();
                } else {
                    int v = graph[u][index++];
                    if (!seen[v]) {
                        seen[v] = true;
                        stack.push_back({v, 0});
                    }
                }
            }
        }
    fill(seen.begin(), seen.end(), false);
    long long answer = 0;
    for (auto it = order.rbegin(); it != order.rend(); ++it)
        if (!seen[*it]) {
            vector<int> todo{*it};
            seen[*it] = true;
            for (size_t i = 0; i < todo.size(); ++i)
                for (int v : reverse[todo[i]])
                    if (!seen[v]) {
                        seen[v] = true;
                        todo.push_back(v);
                    }
            long long size = todo.size();
            answer += size * (size - 1) / 2;
        }
    cout << answer << '\n';
}
