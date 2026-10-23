#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, target;
    cin >> n >> m >> target;
    vector<int> basic(n), unit(n);
    vector<vector<int>> goods(n);
    for (int i = 0; i < n; ++i)
        cin >> basic[i] >> unit[i];
    for (int i = 0; i < m; ++i) {
        int value, warehouse;
        cin >> value >> warehouse;
        goods[warehouse].push_back(value);
    }
    int bound = 0;
    for (int i = 0; i < n; ++i)
        if (!goods[i].empty())
            bound += basic[i] + unit[i] * goods[i].size();
    const int NEG = -1000000000;
    vector<int> dp(bound + 1, NEG);
    dp[0] = 0;
    int previous_bound = 0;
    for (int i = 0; i < n; ++i) {
        if (goods[i].empty())
            continue;
        sort(goods[i].begin(), goods[i].end(), greater<int>());
        vector<int> next = dp;
        int value = 0;
        for (size_t k = 1; k <= goods[i].size(); ++k) {
            value += goods[i][k - 1];
            int cost = basic[i] + int(k) * unit[i];
            for (int old = 0; old <= previous_bound; ++old)
                if (dp[old] != NEG)
                    next[old + cost] = max(next[old + cost], dp[old] + value - cost);
        }
        previous_bound += basic[i] + unit[i] * goods[i].size();
        dp.swap(next);
    }
    for (int cost = 0; cost <= bound; ++cost)
        if (dp[cost] >= target) {
            cout << cost << '\n';
            return 0;
        }
}
