#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
long long hundredths(string s) {
    bool neg = s[0] == '-';
    if (neg || s[0] == '+')
        s = s.substr(1);
    size_t p = s.find('.');
    long long v = stoll(s.substr(0, p)) * 100;
    if (p != string::npos) {
        string frac = s.substr(p + 1);
        while (frac.size() < 2)
            frac += '0';
        v += stoll(frac);
    }
    return neg ? -v : v;
}
int main() {
    int n, a, inside = 0;
    cin >> n >> a;
    long long r = 100LL * a;
    for (int i = 0; i < n; i++) {
        string sx, sy;
        cin >> sx >> sy;
        long long x = hundredths(sx), y = hundredths(sy);
        inside += x * x + y * y <= r * r;
    }
    cout << fixed << setprecision(8) << 4.0 * inside / n << '\n';
}
