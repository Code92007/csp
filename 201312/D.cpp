#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
constexpr int MOD = 1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> input;
    int x;
    while (cin >> x)
        input.push_back(x);
    if (input.empty())
        return 0;
    // Original CSP input is one n; the archived OJ also provides a T-case variant.
    vector<int> queries = input.size() == 1 ? input : vector<int>(input.begin() + 1, input.end());
    int maximum = *max_element(queries.begin(), queries.end());
    vector<int> answer(maximum + 1);
    array<int, 16> dp{};
    dp[0] = 1;
    for (int len = 0; len < maximum; ++len) {
        array<int, 16> next{};
        for (int mask = 0; mask < 16; ++mask)
            for (int digit = 0; digit < 4; ++digit) {
                if (len == 0 && digit == 0)
                    continue;
                if (digit == 0 && (mask & 2))
                    continue;
                if (digit == 1 && !(mask & 1))
                    continue;
                if (digit == 2 && (mask & 8))
                    continue;
                if (digit == 3 && !(mask & 4))
                    continue;
                int to = mask | (1 << digit);
                next[to] = (next[to] + dp[mask]) % MOD;
            }
        dp = next;
        answer[len + 1] = dp[15];
    }
    for (int n : queries)
        cout << answer[n] << '\n';
}
