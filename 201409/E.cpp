#include <functional>
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
using Matrix = vector<vector<int>>;
Matrix multiply(const Matrix &a, const Matrix &b) {
    int s = a.size();
    Matrix c(s, vector<int>(s));
    for (int i = 0; i < s; ++i)
        for (int k = 0; k < s; ++k)
            if (a[i][k])
                for (int j = 0; j < s; ++j)
                    if (b[k][j])
                        c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
    return c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    int m;
    cin >> n >> m;
    if ((n % 3) * (m % 3) % 3) {
        cout << 0 << '\n';
        return 0;
    }
    int s = 1 << m, full = s - 1;
    Matrix a(s, vector<int>(s));
    for (int initial = 0; initial < s; ++initial) {
        function<void(int, int)> dfs = [&](int occupied, int next) {
            if (occupied == full) {
                ++a[initial][next];
                return;
            }
            int c = 0;
            while (occupied >> c & 1)
                ++c;
            for (int left = c - 1; left <= c; ++left)
                if (left >= 0 && left + 1 < m)
                    for (int missing = 0; missing < 4; ++missing) {
                        int upper = 0, lower = 0;
                        for (int cell = 0; cell < 4; ++cell)
                            if (cell != missing) {
                                if (cell < 2)
                                    upper |= 1 << (left + cell);
                                else
                                    lower |= 1 << (left + cell - 2);
                            }
                        if (!(upper >> c & 1) || (upper & occupied) || (lower & next))
                            continue;
                        dfs(occupied | upper, next | lower);
                    }
        };
        dfs(initial, 0);
    }
    vector<int> dp(s);
    dp[0] = 1;
    while (n) {
        if (n & 1) {
            vector<int> next(s);
            for (int i = 0; i < s; ++i)
                if (dp[i])
                    for (int j = 0; j < s; ++j)
                        next[j] = (next[j] + 1LL * dp[i] * a[i][j]) % MOD;
            dp.swap(next);
        }
        n >>= 1;
        if (n)
            a = multiply(a, a);
    }
    cout << dp[0] << '\n';
}
