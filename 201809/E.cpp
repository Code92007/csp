#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;
using Polynomial = vector<int>;
int power(int a, long long n) {
    int r = 1;
    for (; n; n >>= 1, a = 1LL * a * a % MOD)
        if (n & 1)
            r = 1LL * r * a % MOD;
    return r;
}
void ntt(Polynomial &a, bool inverse) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int root = power(3, (MOD - 1) / len);
        if (inverse)
            root = power(root, MOD - 2);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j], v = 1LL * a[i + j + len / 2] * w % MOD;
                int x = u + v, y = u - v;
                if (x >= MOD)
                    x -= MOD;
                if (y < 0)
                    y += MOD;
                a[i + j] = x;
                a[i + j + len / 2] = y;
                w = 1LL * w * root % MOD;
            }
        }
    }
    if (inverse) {
        int inv = power(n, MOD - 2);
        for (int &x : a)
            x = 1LL * x * inv % MOD;
    }
}
Polynomial multiply(Polynomial a, Polynomial b) {
    if (a.empty() || b.empty())
        return {};
    int size = a.size() + b.size() - 1;
    if (min(a.size(), b.size()) <= 32) {
        Polynomial c(size);
        for (int i = 0; i < int(a.size()); ++i)
            for (int j = 0; j < int(b.size()); ++j)
                c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % MOD;
        return c;
    }
    int n = 1;
    while (n < size)
        n <<= 1;
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; ++i)
        a[i] = 1LL * a[i] * b[i] % MOD;
    ntt(a, true);
    a.resize(size);
    return a;
}
Polynomial inverse(const Polynomial &a, int size) {
    Polynomial b{power(a[0], MOD - 2)};
    while (int(b.size()) < size) {
        int len = min(size, 2 * int(b.size()));
        Polynomial cut(a.begin(), a.begin() + min(len, int(a.size())));
        auto product = multiply(cut, b);
        product.resize(len);
        for (int &x : product)
            x = x ? MOD - x : 0;
        product[0] = (product[0] + 2) % MOD;
        b = multiply(b, product);
        b.resize(len);
    }
    return b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    long long l, r;
    cin >> m >> l >> r;
    int count = int(r - l + 1);
    Polynomial c(m + 1);
    c[0] = 1;
    for (int i = 1, k; i <= m; ++i) {
        cin >> k;
        c[i] = k ? MOD - k : 0;
    }
    Polynomial characteristic(c.rbegin(), c.rend()), reversedInverse = inverse(c, m);
    auto remainder = [&](Polynomial a) {
        if (int(a.size()) <= m) {
            a.resize(m);
            return a;
        }
        int length = a.size() - m;
        Polynomial high(a.rbegin(), a.rbegin() + length),
            inv(reversedInverse.begin(), reversedInverse.begin() + length);
        auto quotient = multiply(high, inv);
        quotient.resize(length);
        reverse(quotient.begin(), quotient.end());
        auto product = multiply(quotient, characteristic);
        a.resize(m);
        for (int i = 0; i < m; ++i) {
            a[i] -= product[i];
            if (a[i] < 0)
                a[i] += MOD;
        }
        return a;
    };
    Polynomial result(m), base(m);
    result[0] = 1;
    if (m == 1)
        base[0] = c[1] ? MOD - c[1] : 0;
    else
        base[1] = 1;
    while (l) {
        if (l & 1)
            result = remainder(multiply(result, base));
        l >>= 1;
        if (l)
            base = remainder(multiply(base, base));
    }
    auto prefix = inverse(c, m + count - 1);
    reverse(result.begin(), result.end());
    auto answer = multiply(result, prefix);
    for (int i = 0; i < count; ++i)
        cout << answer[m - 1 + i] << '\n';
}
