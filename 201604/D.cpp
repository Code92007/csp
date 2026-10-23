#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> begin(n * m, 1), end(n * m, 0);
    int last = 0;
    for (int i = 0; i < k; ++i) {
        int r, c, a, b;
        cin >> r >> c >> a >> b;
        int u = (r - 1) * m + c - 1;
        begin[u] = a;
        end[u] = b;
        last = max(last, b);
    }
    int limit = last + n + m;
    vector<vector<bool>> seen(limit + 1, vector<bool>(n * m));
    vector<pair<int, int>> queue{{0, 0}};
    seen[0][0] = true;
    const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    for (size_t head = 0; head < queue.size(); ++head) {
        auto [u, time] = queue[head];
        if (u == n * m - 1) {
            cout << time << '\n';
            return 0;
        }
        if (time == limit)
            continue;
        for (int d = 0; d < 4; ++d) {
            int x = u / m + dx[d], y = u % m + dy[d], t = time + 1;
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            int v = x * m + y;
            if (!seen[t][v] && !(begin[v] <= t && t <= end[v])) {
                seen[t][v] = true;
                queue.push_back({v, t});
            }
        }
    }
}
