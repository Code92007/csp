#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using Mask = uint32_t;
using Word = uint64_t;
using Layer = vector<unordered_map<Mask, int>>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, limit, k;
    cin >> n >> m >> limit >> k;
    vector<int> color(n), from(m), to(m), weight(m);
    for (int &x : color)
        cin >> x;
    for (int &x : from)
        cin >> x;
    for (int &x : to)
        cin >> x;
    for (int &x : weight)
        cin >> x;
    vector<vector<pair<int, int>>> g(n), rg(n);
    for (int i = 0; i < m; ++i) {
        g[from[i]].push_back({to[i], weight[i]});
        rg[to[i]].push_back({from[i], weight[i]});
    }
    auto compute = [&](int source, const vector<vector<pair<int, int>>> &edges) {
        vector<Layer> dp(5, Layer(n));
        dp[0][source][Mask(1) << color[source]] = 0;
        for (int d = 0; d < 4 && d + 1 < limit; ++d)
            for (int u = 0; u < n; ++u)
                for (auto [mask, value] : dp[d][u])
                    for (auto [v, w] : edges[u])
                        if (!(mask >> color[v] & 1)) {
                            auto &best = dp[d + 1][v][mask | (Mask(1) << color[v])];
                            best = max(best, value + w);
                        }
        return dp;
    };
    auto forward = compute(0, g), backward = compute(n - 1, rg);
    int answer = 0;
    for (int u = 0; u < n; ++u)
        for (int d = 0; d <= 4 && d < limit; ++d) {
            if (forward[d][u].empty())
                continue;
            int cap = min(4, limit - 1 - d);
            vector<pair<int, Mask>> candidates;
            for (int e = 0; e <= cap; ++e)
                for (auto [mask, value] : backward[e][u])
                    candidates.push_back({value, mask});
            sort(candidates.rbegin(), candidates.rend());
            int words = (int(candidates.size()) + 63) / 64;
            if (!words)
                continue;
            vector<vector<Word>> bad(k, vector<Word>(words));
            for (int i = 0; i < int(candidates.size()); ++i) {
                Mask mask = candidates[i].second;
                while (mask) {
                    int c = __builtin_ctz(mask);
                    mask &= mask - 1;
                    bad[c][i / 64] |= Word(1) << (i % 64);
                }
            }
            for (auto [key, value] : forward[d][u]) {
                Mask mask = key ^ (Mask(1) << color[u]);
                vector<int> colors;
                while (mask) {
                    colors.push_back(__builtin_ctz(mask));
                    mask &= mask - 1;
                }
                for (int j = 0; j < words; ++j) {
                    Word excluded = 0;
                    for (int c : colors)
                        excluded |= bad[c][j];
                    Word valid = ~excluded;
                    if (valid) {
                        int index = j * 64 + __builtin_ctzll(valid);
                        if (index < int(candidates.size()))
                            answer = max(answer, value + candidates[index].first);
                        break;
                    }
                }
            }
        }
    cout << answer << '\n';
}
