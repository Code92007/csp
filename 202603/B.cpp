#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    long long total = 0;
    vector<long long> dp(m + 1);
    vector<pair<int, int>> flex;
    while (n--) {
        int o, t, a, b;
        cin >> o >> t >> a >> b;
        total += t;
        if (!o)
            flex.push_back({a, b});
        else
            for (int j = m; j >= a; j--)
                dp[j] = max(dp[j], dp[j - a] + b);
    }
    sort(flex.begin(), flex.end(),
         [](auto x, auto y) { return 1LL * x.second * y.first > 1LL * y.second * x.first; });
    vector<long double> gain(m + 1);
    int used = 0;
    for (auto [a, b] : flex)
        for (int j = 0; j < a && used < m; j++) {
            gain[used + 1] = gain[used] + (long double)b / a;
            ++used;
        }
    while (used < m) {
        gain[used + 1] = gain[used];
        ++used;
    }
    long double best = 0;
    for (int j = 0; j <= m; j++)
        best = max(best, dp[j] + gain[m - j]);
    cout << fixed << setprecision(8) << total - best << '\n';
}
