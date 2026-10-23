#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using I = __int128_t;
ll inverse(ll a, ll mod) {
    ll b = mod, x = 1, y = 0;
    while (b) {
        ll q = a / b;
        ll c = a - q * b;
        a = b;
        b = c;
        c = x - q * y;
        x = y;
        y = c;
    }
    return (x % mod + mod) % mod;
}
void print(I x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    while (x) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> period(m);
    vector<vector<ll>> offset(m, vector<ll>(n, -1));
    for (int i = 0; i < m; ++i) {
        int length;
        cin >> length;
        for (int j = 0; j < length; ++j) {
            int s;
            ll travel;
            cin >> s >> travel;
            offset[i][s - 1] = period[i];
            period[i] += travel;
        }
    }
    const I INF = I(1) << 120;
    vector<I> dist(m, INF), answer(n, INF);
    vector<bool> used(m);
    for (int i = 0; i < m; ++i)
        if (offset[i][0] >= 0)
            dist[i] = offset[i][0];
    for (int iteration = 0; iteration < m; ++iteration) {
        int u = -1;
        for (int i = 0; i < m; ++i)
            if (!used[i] && (u < 0 || dist[i] < dist[u]))
                u = i;
        if (u < 0 || dist[u] == INF)
            break;
        used[u] = true;
        for (int s = 0; s < n; ++s)
            if (offset[u][s] >= 0) {
                I t = offset[u][s];
                if (t < dist[u])
                    t += (dist[u] - t + period[u] - 1) / period[u] * period[u];
                answer[s] = min(answer[s], t);
            }
        for (int v = 0; v < m; ++v)
            if (!used[v]) {
                ll g = gcd(period[u], period[v]), mod = period[v] / g;
                ll inv = mod == 1 ? 0 : inverse(period[u] / g, mod);
                I cycle = I(period[u]) * mod;
                for (int s = 0; s < n; ++s)
                    if (offset[u][s] >= 0 && offset[v][s] >= 0) {
                        ll difference = offset[v][s] - offset[u][s];
                        if (difference % g)
                            continue;
                        I factor = mod == 1 ? 0 : (I(difference / g) * inv % mod + mod) % mod;
                        I time = (offset[u][s] + I(period[u]) * factor) % cycle;
                        if (time < dist[u])
                            time += (dist[u] - time + cycle - 1) / cycle * cycle;
                        dist[v] = min(dist[v], time);
                    }
            }
    }
    for (int s = 1; s < n; ++s) {
        if (answer[s] == INF)
            cout << "inf";
        else
            print(answer[s]);
        cout << '\n';
    }
}
