#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using P = pair<ll, int>; // adjusted cost, negative number of completed tasks
P operator+(P a, P b) {
    return {a.first + b.first, a.second + b.second};
}
P operator-(P a) {
    return {-a.first, -a.second};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll budget;
    cin >> n >> budget;
    vector<ll> a(n), b(n);
    ll full = 0;
    for (auto &x : a) {
        cin >> x;
        full += x;
    }
    for (auto &x : b) {
        cin >> x;
        full += x;
    }
    if (full <= budget) {
        cout << n << '\n';
        return 0;
    }
    auto evaluate = [&](ll reward) {
        priority_queue<P, vector<P>, greater<P>> slopes;
        P base{0, 0};
        for (int i = 0; i < n; ++i) {
            slopes.push({a[i], 0});
            P finish{b[i] - reward, -1};
            P change = slopes.top() + finish;
            if (change < P{0, 0}) {
                base = base + change;
                slopes.pop();
                slopes.push(-finish);
            }
        }
        ll count = -base.second;
        return pair<ll, ll>{base.first + reward * count, count};
    };
    ll lo = 0, hi = 2000000001LL;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (evaluate(mid).first <= budget)
            lo = mid;
        else
            hi = mid;
    }
    auto [cost, count] = evaluate(lo);
    // All additional tasks at the next breakpoint have marginal cost hi.
    cout << count + (budget - cost) / hi << '\n';
}
