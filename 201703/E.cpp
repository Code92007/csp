#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll a, b, q, x;
    cin >> n >> m >> a >> b >> q >> x;
    int h = n - 1;
    vector<int> vertical(h * m), horizontal((h - 1) * (m - 1));
    auto next = [&]() {
        x = (a * x + b) % q;
        return int(x);
    };
    for (int row = 0; row < h; ++row)
        for (int col = 0; col < m; ++col)
            vertical[col * h + row] = next();
    for (int row = 0; row < h - 1; ++row)
        for (int col = 0; col < m - 1; ++col)
            horizontal[col * (h - 1) + row] = next();
    vector<ll> dp(h);
    for (int row = 0; row < h; ++row)
        dp[row] = vertical[row];
    for (int col = 1; col < m; ++col) {
        int offset = (col - 1) * (h - 1);
        for (int row = 1; row < h; ++row)
            dp[row] = min(dp[row], dp[row - 1] + horizontal[offset + row - 1]);
        for (int row = h - 2; row >= 0; --row)
            dp[row] = min(dp[row], dp[row + 1] + horizontal[offset + row]);
        for (int row = 0; row < h; ++row)
            dp[row] += vertical[col * h + row];
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
}
