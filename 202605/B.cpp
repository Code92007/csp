#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; int k, days;
    if (!(cin >> n >> k >> days)) return 0;
    auto feasible = [&](ll robots) {
        ll left = n;
        for (int day = 0; day < days; ++day) {
            // ceil(left*k/100), without multiplying a value up to 1e18 by k.
            ll wasted = left / 100 * k + ((left % 100) * k + 99) / 100;
            left -= wasted;
            if (left < robots) return false;
            left -= robots;
        }
        return true;
    };
    ll lo = 0, hi = 1000000000;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (feasible(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << '\n';
}
