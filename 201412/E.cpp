#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
struct MinCostFlow {
    struct Edge {
        int to, reverse, capacity, cost;
    };
    vector<vector<Edge>> g;
    explicit MinCostFlow(int n) : g(n) {}
    void add(int u, int v, int cap, int cost) {
        Edge a{v, int(g[v].size()), cap, cost}, b{u, int(g[u].size()), 0, -cost};
        g[u].push_back(a);
        g[v].push_back(b);
    }
    ll solve(int source, int sink, int required) {
        int n = g.size();
        vector<ll> potential(n), dist(n);
        vector<int> parent(n), index(n);
        ll answer = 0;
        const ll INF = 1LL << 60;
        while (required) {
            fill(dist.begin(), dist.end(), INF);
            dist[source] = 0;
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
            q.push({0, source});
            while (!q.empty()) {
                auto [d, u] = q.top();
                q.pop();
                if (d != dist[u])
                    continue;
                for (int j = 0; j < int(g[u].size()); ++j) {
                    auto e = g[u][j];
                    ll nd = d + e.cost + potential[u] - potential[e.to];
                    if (e.capacity && nd < dist[e.to]) {
                        dist[e.to] = nd;
                        parent[e.to] = u;
                        index[e.to] = j;
                        q.push({nd, e.to});
                    }
                }
            }
            if (dist[sink] == INF)
                return -1;
            for (int u = 0; u < n; ++u)
                if (dist[u] != INF)
                    potential[u] += dist[u];
            int flow = required;
            for (int v = sink; v != source; v = parent[v])
                flow = min(flow, g[parent[v]][index[v]].capacity);
            for (int v = sink; v != source; v = parent[v]) {
                auto &e = g[parent[v]][index[v]];
                answer += ll(flow) * e.cost;
                e.capacity -= flow;
                g[v][e.reverse].capacity += flow;
            }
            required -= flow;
        }
        return answer;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int source = 7 * n, sink = source + 1, total = 0;
    MinCostFlow flow(sink + 1);
    for (int i = 0; i < n; ++i) {
        array<int, 7> a{}, b{};
        for (int &v : a)
            cin >> v;
        for (int &v : b)
            cin >> v;
        int cap, cost;
        cin >> cap >> cost;
        for (int j = 0; j < 7; ++j) {
            flow.add(source, 7 * i + j, a[j], 0);
            flow.add(7 * i + j, sink, b[j], 0);
            flow.add(7 * i + j, 7 * i + (j + 1) % 7, cap, cost);
            total += b[j];
        }
    }
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        for (int j = 0; j < 7; ++j) {
            flow.add(7 * u + j, 7 * v + j, 1000000000, c);
            flow.add(7 * v + j, 7 * u + j, 1000000000, c);
        }
    }
    cout << flow.solve(source, sink, total) << '\n';
}
