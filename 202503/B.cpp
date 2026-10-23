#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(m + 1), dp(n + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int used = 1; used <= n; used++)
        for (int today = 1; today <= m && today <= used; today++)
            dp[used] = max(dp[used], dp[used - today] + a[today]);
    cout << dp[n] << '\n';
}
