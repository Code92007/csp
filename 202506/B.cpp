#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    --x;
    --y;
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    int ans = 0, dx[] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        ++ans;
        if (dist[u][v] == k)
            continue;
        for (int i = 0; i < 8; i++) {
            int a = u + dx[i], b = v + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < n && dist[a][b] == -1) {
                dist[a][b] = dist[u][v] + 1;
                q.push({a, b});
            }
        }
    }
    cout << ans << '\n';
}
