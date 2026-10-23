#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L, r, t;
    cin >> n >> L >> r >> t;
    vector<vector<long long>> s(n + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            long long x;
            cin >> x;
            s[i][j] = x + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int u = max(1, i - r), v = max(1, j - r), x = min(n, i + r), y = min(n, j + r);
            long long sum = s[x][y] - s[u - 1][y] - s[x][v - 1] + s[u - 1][v - 1];
            if (sum <= 1LL * t * (x - u + 1) * (y - v + 1))
                ++ans;
        }
    cout << ans << '\n';
}
