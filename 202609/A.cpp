#include <iostream>
#include <string>
#include <vector>
using namespace std;
using i128 = __int128_t;

long long scaled(const string& s, int places) {
    size_t dot = s.find('.');
    string whole = dot == string::npos ? s : s.substr(0, dot);
    string fraction = dot == string::npos ? "" : s.substr(dot + 1);
    fraction.resize(places, '0');
    long long factor = 1;
    for (int i = 0; i < places; ++i) factor *= 10;
    return stoll(whole) * factor + stoll(fraction.empty() ? "0" : fraction);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    long long totalMean = 0, variance = 0;
    string token;
    for (int i = 0; i < n; ++i) {
        cin >> token;
        totalMean += scaled(token, 3);
    }
    for (int i = 0; i < n; ++i) {
        cin >> token;
        long long x = scaled(token, 3);
        variance += x * x;
    }
    vector<long long> x(k);
    vector<string> value(k);
    for (auto& v : x) { cin >> token; v = scaled(token, 3); }
    for (auto& v : value) cin >> v;
    long long numerator = 1000LL * m - totalMean;
    int chosen = k - 1;
    for (int i = 0; i + 1 < k; ++i) {
        i128 left = i128(2000) * numerator;
        i128 middle = x[i] + x[i + 1];
        // All quantities are nonnegative: compare to the exact midpoint.
        if (left * left <= middle * middle * variance) {
            chosen = i;
            break;
        }
    }
    cout << value[chosen] << '\n';
}
