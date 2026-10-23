#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;
constexpr int MOD = 998244353;
using Values = array<int, 5>;
Values local(int p, int exponent) {
    vector<i64> power(3 * exponent + 1, 1);
    for (int i = 1; i <= 3 * exponent; ++i)
        power[i] = power[i - 1] * p % MOD;
    Values ans{};
    for (int x = -exponent; x <= exponent; ++x) {
        for (int y = -exponent; y <= exponent; ++y) {
            if (x + y > exponent)
                continue;
            int w = power[exponent - x - y];
            auto add = [&](int index) { ans[index] = (ans[index] + w) % MOD; };
            add(0);
            if (x == 0)
                add(1);
            if (x == y)
                add(2);
            if (x == -y)
                add(3);
            if (y == -2 * x)
                add(4);
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int op, n;
    cin >> op >> n;
    int limit = sqrt(n);
    vector<int> least(n + 1), primes;
    for (int i = 2; i <= n; ++i) {
        if (!least[i]) {
            least[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > least[i] || i64(p) * i > n)
                break;
            least[i * p] = p;
        }
    }
    vector<vector<Values>> table(limit + 1);
    for (int p : primes) {
        if (p > limit)
            break;
        table[p].push_back({});
        for (i64 power = p, e = 1; power <= n; power *= p, ++e)
            table[p].push_back(local(p, int(e)));
    }
    int count = op ? 5 : 1;
    vector<vector<int>> f(count, vector<int>(n + 1));
    for (auto &row : f)
        row[1] = 1;
    i64 answer = op ? 0 : 1;
    for (int i = 2; i <= n; ++i) {
        int p = least[i], rest = i, exponent = 0;
        do {
            rest /= p;
            ++exponent;
        } while (rest % p == 0);
        Values v;
        if (p <= limit)
            v = table[p][exponent];
        else {
            i64 p2 = i64(p) * p % MOD, p3 = p2 * p % MOD;
            v = {int((p3 + 2 * p2 + 3LL * p + 2) % MOD), int((p2 + p + 1) % MOD),
                 int((p3 + p) % MOD), int(3LL * p % MOD), p};
        }
        for (int j = 0; j < count; ++j)
            f[j][i] = i64(f[j][rest]) * v[j] % MOD;
        i64 value = f[0][i];
        if (op)
            value += -2LL * f[1][i] - f[2][i] - f[3][i] - 2LL * f[4][i] + 5LL * i;
        answer = (answer + value) % MOD;
    }
    cout << (answer + MOD) % MOD << '\n';
}
