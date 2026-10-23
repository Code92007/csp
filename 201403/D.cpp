#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    long long radius;
    cin >> n >> m >> k >> radius;
    int total = n + m;
    vector<long long> x(total), y(total);
    for (int i = 0; i < total; ++i)
        cin >> x[i] >> y[i];
    vector<vector<int>> graph(total);
    for (int i = 0; i < total; ++i)
        for (int j = 0; j < i; ++j) {
            long long dx = x[i] - x[j], dy = y[i] - y[j];
            if (dx * dx + dy * dy <= radius * radius) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    vector<vector<int>> distance(total, vector<int>(k + 1, -1));
    vector<pair<int, int>> queue{{0, 0}};
    distance[0][0] = 0;
    for (size_t head = 0; head < queue.size(); ++head) {
        auto [u, used] = queue[head];
        if (u == 1) {
            cout << distance[u][used] - 1 << '\n';
            return 0;
        }
        for (int v : graph[u]) {
            int next = used + (v >= n);
            if (next <= k && distance[v][next] < 0) {
                distance[v][next] = distance[u][used] + 1;
                queue.push_back({v, next});
            }
        }
    }
}
