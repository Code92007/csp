#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
constexpr long long MOD = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, long long>> groups, next;
    long long answer = 0;
    for (int r = 1; r <= n; ++r) {
        int x;
        cin >> x;
        next.clear();
        next.push_back({x, r});
        for (auto [g, sum] : groups) {
            int value = gcd(g, x);
            if (next.back().first == value)
                next.back().second = (next.back().second + sum) % MOD;
            else
                next.push_back({value, sum});
        }
        groups.swap(next);
        for (auto [g, sum] : groups)
            answer = (answer + sum * r % MOD * g) % MOD;
    }
    cout << answer << '\n';
}
