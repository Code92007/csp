#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m, p;
        cin >> n >> m >> p;
        string terminal;
        cin >> terminal;
        int last = terminal.find_last_of('1');
        vector<array<int, 6>> cost(n);
        for (auto &a : cost)
            a.fill(-1);
        for (int i = 0, u, v, w; i < m; ++i) {
            cin >> u >> v >> w;
            cost[u - 1][v - u - 1] = w;
        }
        vector<int> codes{0};
        unordered_map<int, int> id{{0, 0}};
        vector<vector<int>> transition;
        for (size_t index = 0; index < codes.size(); ++index) {
            int code = codes[index];
            vector<int> row(1 << p, -1);
            for (int mask = 0; mask < (1 << p); ++mask) {
                array<int, 7> parent{}, selected{};
                iota(parent.begin(), parent.end(), 0);
                auto root = [&](int u) {
                    while (parent[u] != u)
                        u = parent[u];
                    return u;
                };
                auto unite = [&](int u, int v) { parent[root(u)] = root(v); };
                for (int i = 0; i < p; ++i) {
                    int label = (code >> (3 * i)) & 7;
                    selected[i] = label != 0;
                    if (label)
                        for (int j = 0; j < i; ++j)
                            if (((code >> (3 * j)) & 7) == label)
                                unite(i, j);
                }
                for (int j = 0; j < p; ++j)
                    if (mask >> j & 1) {
                        selected[0] = selected[j + 1] = 1;
                        unite(0, j + 1);
                    }
                if (selected[0]) {
                    bool stays = false, other = false;
                    for (int j = 1; j <= p; ++j)
                        if (selected[j]) {
                            if (root(j) == root(0))
                                stays = true;
                            else
                                other = true;
                        }
                    if (!stays) {
                        row[mask] = other ? -1 : -2;
                        continue;
                    }
                }
                array<int, 7> label{};
                int count = 0, next = 0;
                for (int j = 1; j <= p; ++j)
                    if (selected[j]) {
                        int r = root(j);
                        if (!label[r])
                            label[r] = ++count;
                        next |= label[r] << (3 * (j - 1));
                    }
                auto [it, inserted] = id.emplace(next, codes.size());
                if (inserted)
                    codes.push_back(next);
                row[mask] = it->second;
            }
            transition.push_back(std::move(row));
        }
        const ll INF = 1LL << 60;
        vector<ll> dp(codes.size(), INF);
        dp[0] = 0;
        ll answer = INF;
        for (int i = 0; i < n; ++i) {
            vector<ll> next(codes.size(), INF);
            int available = 0;
            for (int j = 0; j < p; ++j)
                if (cost[i][j] >= 0)
                    available |= 1 << j;
            vector<pair<int, ll>> options;
            for (int mask = available;; mask = (mask - 1) & available) {
                ll sum = 0;
                for (int j = 0; j < p; ++j)
                    if (mask >> j & 1)
                        sum += cost[i][j];
                options.push_back({mask, sum});
                if (!mask)
                    break;
            }
            for (int state = 0; state < int(codes.size()); ++state) {
                if (dp[state] == INF)
                    continue;
                for (auto [mask, w] : options) {
                    if (terminal[i] == '1' && !(codes[state] & 7) && !mask)
                        continue;
                    int to = transition[state][mask];
                    if (to == -2) {
                        if (i >= last)
                            answer = min(answer, dp[state] + w);
                    } else if (to >= 0)
                        next[to] = min(next[to], dp[state] + w);
                }
            }
            dp.swap(next);
        }
        cout << answer << '\n';
    }
}
