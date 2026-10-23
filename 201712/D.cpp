#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;
constexpr i64 INF = 4000000000000000000LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<i64>> small(n, vector<i64>(n, INF)), large = small;
    for (int i = 0; i < n; ++i)
        small[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int type, u, v;
        i64 w;
        cin >> type >> u >> v >> w;
        --u;
        --v;
        auto &a = type ? small : large;
        a[u][v] = a[v][u] = min(a[u][v], w);
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            if (small[i][k] < INF)
                for (int j = 0; j < n; ++j)
                    if (small[k][j] < INF)
                        small[i][j] = min(small[i][j], small[i][k] + small[k][j]);
    vector<i64> distance(2 * n, INF);
    vector<bool> done(2 * n);
    distance[0] = 0;
    for (int step = 0; step < 2 * n; ++step) {
        int state = -1;
        for (int i = 0; i < 2 * n; ++i)
            if (!done[i] && (state == -1 || distance[i] < distance[state]))
                state = i;
        if (state == -1 || distance[state] == INF)
            break;
        done[state] = true;
        int u = state / 2, previous = state % 2;
        for (int v = 0; v < n; ++v) {
            if (large[u][v] < INF)
                distance[v * 2] = min(distance[v * 2], distance[state] + large[u][v]);
            if (previous == 0 && v != u && small[u][v] < INF)
                distance[v * 2 + 1] =
                    min(distance[v * 2 + 1], distance[state] + small[u][v] * small[u][v]);
        }
    }
    cout << min(distance[2 * n - 2], distance[2 * n - 1]) << '\n';
}
