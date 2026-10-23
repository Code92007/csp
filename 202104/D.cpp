#include <iostream>
#include <vector>
using namespace std;
constexpr long long MOD = 1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int maximum = a.back() - a.front();
    vector<vector<int>> divisors(maximum + 1);
    for (int d = 1; d <= maximum; ++d)
        for (int multiple = d; multiple <= maximum; multiple += d)
            divisors[multiple].push_back(d);
    vector<int> blocked(maximum + 1, -1);
    vector<long long> dp(n);
    dp[0] = 1;
    for (int l = 0; l < n - 1; ++l)
        for (int r = l + 1; r < n; ++r) {
            int distance = a[r] - a[l], ways = 0;
            for (int d : divisors[distance])
                if (d < distance && blocked[d] != l)
                    ++ways;
            dp[r] = (dp[r] + dp[l] * ways) % MOD;
            for (int d : divisors[distance])
                blocked[d] = l;
        }
    cout << dp.back() << '\n';
}
