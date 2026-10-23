#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
struct Flow {
    struct Edge {
        int to, reverse;
        ll capacity;
    };
    vector<vector<Edge>> g;
    vector<int> level, current;
    explicit Flow(int n) : g(n), level(n), current(n) {}
    void add(int u, int v, ll c) {
        Edge a{v, int(g[v].size()), c}, b{u, int(g[u].size()), 0};
        g[u].push_back(a);
        g[v].push_back(b);
    }
    ll dfs(int u, int sink, ll f) {
        if (u == sink)
            return f;
        for (int &i = current[u]; i < int(g[u].size()); ++i) {
            auto &e = g[u][i];
            if (e.capacity && level[e.to] == level[u] + 1) {
                ll sent = dfs(e.to, sink, min(f, e.capacity));
                if (sent) {
                    e.capacity -= sent;
                    g[e.to][e.reverse].capacity += sent;
                    return sent;
                }
            }
        }
        return 0;
    }
    ll run(int source, int sink) {
        ll ans = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            queue<int> q;
            q.push(source);
            level[source] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto e : g[u])
                    if (e.capacity && level[e.to] < 0) {
                        level[e.to] = level[u] + 1;
                        q.push(e.to);
                    }
            }
            if (level[sink] < 0)
                return ans;
            fill(current.begin(), current.end(), 0);
            while (ll sent = dfs(source, sink, 1LL << 60))
                ans += sent;
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int source = 2 * n, sink = source + 1;
    Flow flow(sink + 1);
    ll positives = 0;
    const ll INF = 1LL << 60;
    auto weight = [&](int u, ll x) {
        if (x > 0) {
            flow.add(source, u, x);
            positives += x;
        } else if (x < 0)
            flow.add(u, sink, -x);
    };
    for (int i = 0; i < n; ++i) {
        ll l, r, a, b, c;
        cin >> l >> r >> a >> b >> c;
        auto f = [&](ll x) { return a * x * x + b * x + c; };
        ll inside = max(f(l + 1), f(r - 1));
        if (a < 0) {
            ll center = -b / (2 * a);
            for (ll x = center - 2; x <= center + 2; ++x)
                if (l < x && x < r)
                    inside = max(inside, f(x));
        }
        ll endpoint = max(f(l), f(r));
        weight(i, inside);
        weight(i + n, endpoint - inside);
        flow.add(i + n, i, INF);
    }
    while (m--) {
        int z, x, y;
        cin >> z >> x >> y;
        --x;
        --y;
        flow.add(y + (z == 2 ? n : 0), x, INF);
    }
    cout << positives - flow.run(source, sink) << '\n';
}
