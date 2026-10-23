#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<int> distance(n * n, -1), queue;
    vector<long long> demand(n * n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        int u = (x - 1) * n + y - 1;
        if (distance[u] < 0) {
            distance[u] = 0;
            queue.push_back(u);
        }
    }
    for (int i = 0; i < k; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        demand[(x - 1) * n + y - 1] += c;
    }
    for (int i = 0; i < d; ++i) {
        int x, y;
        cin >> x >> y;
        distance[(x - 1) * n + y - 1] = -2;
    }
    const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    long long answer = 0;
    for (size_t head = 0; head < queue.size(); ++head) {
        int u = queue[head];
        answer += demand[u] * distance[u];
        for (int dir = 0; dir < 4; ++dir) {
            int x = u / n + dx[dir], y = u % n + dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= n)
                continue;
            int v = x * n + y;
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                queue.push_back(v);
            }
        }
    }
    cout << answer << '\n';
}
