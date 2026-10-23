#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
using i64 = long long;
struct Station {
    i64 x, y, r, cost;
    bool used = false;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<i64> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    vector<Station> stations(m);
    for (auto &s : stations)
        cin >> s.x >> s.y >> s.r >> s.cost;
    const i64 INF = numeric_limits<i64>::max() / 4;
    vector<i64> distance(n, INF);
    vector<bool> done(n);
    distance[0] = 0;
    for (int step = 0; step < n; ++step) {
        int u = -1;
        for (int i = 0; i < n; ++i)
            if (!done[i] && (u == -1 || distance[i] < distance[u]))
                u = i;
        if (u == -1 || distance[u] == INF)
            break;
        done[u] = true;
        if (u == n - 1)
            break;
        for (auto &s : stations) {
            if (s.used || abs(x[u] - s.x) > s.r || abs(y[u] - s.y) > s.r)
                continue;
            s.used = true;
            i64 candidate = distance[u] + s.cost;
            for (int v = 0; v < n; ++v)
                if (!done[v] && candidate < distance[v] && abs(x[v] - s.x) <= s.r &&
                    abs(y[v] - s.y) <= s.r)
                    distance[v] = candidate;
        }
    }
    if (distance[n - 1] == INF)
        cout << "Nan\n";
    else
        cout << distance[n - 1] << '\n';
}
