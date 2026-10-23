#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
struct Neuron {
    double v, u, a, b, c, d;
    int count = 0;
};
struct Edge {
    int to, delay;
    double weight;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, p, T;
    double dt;
    cin >> n >> s >> p >> T >> dt;
    vector<Neuron> a;
    while (int(a.size()) < n) {
        int count;
        Neuron x;
        cin >> count >> x.v >> x.u >> x.a >> x.b >> x.c >> x.d;
        while (count--)
            a.push_back(x);
    }
    vector<int> r(p);
    for (int &x : r)
        cin >> x;
    vector<vector<Edge>> g(n + p);
    int delay = 0;
    while (s--) {
        int u, v, d;
        double w;
        cin >> u >> v >> w >> d;
        g[u].push_back({v, d, w});
        delay = max(delay, d);
    }
    int ring = delay + 1;
    vector<vector<double>> input(ring, vector<double>(n));
    uint64_t seed = 1;
    auto emit = [&](int u, int t) {
        for (auto e : g[u])
            if (t + e.delay <= T)
                input[(t + e.delay) % ring][e.to] += e.weight;
    };
    for (int t = 1; t <= T; t++) {
        for (int j = 0; j < p; j++) {
            seed = seed * 1103515245 + 12345;
            int value = (seed / 65536) % 32768;
            if (r[j] > value)
                emit(n + j, t);
        }
        for (int j = 0; j < n; j++) {
            auto &x = a[j];
            double v = x.v, u = x.u;
            x.v = v + dt * (0.04 * v * v + 5 * v + 140 - u) + input[t % ring][j];
            x.u = u + dt * x.a * (x.b * v - u);
            input[t % ring][j] = 0;
            if (x.v >= 30) {
                x.v = x.c;
                x.u += x.d;
                ++x.count;
                emit(j, t);
            }
        }
    }
    double low = a[0].v, high = low;
    int lc = a[0].count, hc = lc;
    for (auto x : a) {
        low = min(low, x.v);
        high = max(high, x.v);
        lc = min(lc, x.count);
        hc = max(hc, x.count);
    }
    cout << fixed << setprecision(3) << low << ' ' << high << '\n' << lc << ' ' << hc << '\n';
}
