#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
struct Route {
    int from, to, mask, length;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string target;
    cin >> n >> target;
    int bits = target.size(), S = 1 << bits, INF = 1000000000;
    array<int, 26> id;
    id.fill(-1);
    for (int i = 0; i < bits; ++i)
        id[target[i] - 'a'] = i;
    vector<Route> routes(n);
    vector<int> best(26 * 26 * S, INF);
    for (auto &r : routes) {
        string s;
        cin >> s;
        r = {s.front() - 'a', s.back() - 'a', 0, int(s.size()) - 1};
        for (char c : s)
            if (id[c - 'a'] >= 0)
                r.mask |= 1 << id[c - 'a'];
        int &w = best[(r.from * 26 + r.to) * S + r.mask];
        w = min(w, r.length);
    }
    vector<vector<Route>> g(26);
    for (int u = 0; u < 26; ++u)
        for (int v = 0; v < 26; ++v) {
            vector<int> sup(S);
            for (int s = 0; s < S; ++s)
                sup[s] = best[(u * 26 + v) * S + s];
            for (int b = 0; b < bits; ++b)
                for (int s = 0; s < S; ++s)
                    if (!(s >> b & 1))
                        sup[s] = min(sup[s], sup[s | (1 << b)]);
            for (int s = 0; s < S; ++s) {
                int w = best[(u * 26 + v) * S + s];
                if (w == INF)
                    continue;
                bool dominated = false;
                for (int b = 0; b < bits; ++b)
                    if (!(s >> b & 1) && sup[s | (1 << b)] <= w)
                        dominated = true;
                if (!dominated)
                    g[u].push_back({u, v, s, w});
            }
        }
    vector<vector<int>> need(26, vector<int>(26 * S, INF));
    for (int start = 0; start < 26; ++start) {
        auto &dist = need[start];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        dist[start * S] = 0;
        heap.push({0, start * S});
        while (!heap.empty()) {
            auto [d, state] = heap.top();
            heap.pop();
            if (d != dist[state])
                continue;
            int u = state / S, mask = state % S;
            for (auto edge : g[u]) {
                int v = edge.to * S + (mask | edge.mask);
                if (d + edge.length < dist[v]) {
                    dist[v] = d + edge.length;
                    heap.push({dist[v], v});
                }
            }
        }
        // Convert exact masks to "at least these stamps".
        for (int v = 0; v < 26; ++v)
            for (int b = 0; b < bits; ++b)
                for (int s = 0; s < S; ++s)
                    if (!(s >> b & 1))
                        dist[v * S + s] = min(dist[v * S + s], dist[v * S + (s | (1 << b))]);
    }
    for (auto r : routes) {
        int d = need[r.to][r.from * S + ((S - 1) ^ r.mask)];
        cout << (d == INF ? -1 : d + r.length) << '\n';
    }
}
