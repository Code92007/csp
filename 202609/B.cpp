#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int fixedPoint(const string& s, int digits) {
    size_t pos = s.find('.');
    string a = s.substr(0, pos);
    string b = pos == string::npos ? "" : s.substr(pos + 1);
    b.resize(digits, '0');
    int base = 1;
    while (digits--) base *= 10;
    return stoi(a) * base + stoi(b.empty() ? "0" : b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string qText;
    if (!(cin >> n >> m >> qText)) return 0;
    int q = fixedPoint(qText, 3);
    vector<int> benefit(n), risk(n);
    for (int& x : benefit) cin >> x;
    for (int& x : risk) {
        string s; cin >> s;
        x = fixedPoint(s, 1);
        x *= x;
    }
    int maximum = accumulate(benefit.begin(), benefit.end(), 0);
    const int INF = 1000000000;
    vector<int> dp(maximum + 1, INF);
    dp[0] = 0;
    int prefix = 0;
    for (int i = 0; i < n; ++i) {
        prefix += benefit[i];
        for (int v = prefix; v >= benefit[i]; --v) {
            if (dp[v - benefit[i]] != INF)
                dp[v] = min(dp[v], dp[v - benefit[i]] + risk[i]);
        }
    }
    long long limit = 100LL * m * m * 1000000;
    for (int v = maximum; v >= 0; --v) {
        if (dp[v] != INF && 1LL * dp[v] * q * q <= limit) {
            cout << v << '\n';
            break;
        }
    }
}
