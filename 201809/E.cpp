#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
constexpr int MOD = 998244353;
using Polynomial = vector<int>;

int power(int a, long long n) {
    int r = 1;
    for (; n; n >>= 1, a = 1LL * a * a % MOD)
        if (n & 1) r = 1LL * r * a % MOD;
    return r;
}
int transformSize(int need) {
    int n = 1;
    while (n < need) n <<= 1;
    return n;
}

// DIF forward and DIT inverse use the same bit-reversed frequency order.
// Roots are stored once for every butterfly stage, avoiding per-block powers.
void ntt(Polynomial &a, bool inverse) {
    static Polynomial roots{0, 1}, inverseRoots{0, 1};
    int n = int(a.size());
    while (int(roots.size()) < n) {
        int half = int(roots.size());
        roots.resize(2 * half);
        inverseRoots.resize(2 * half);
        int w = power(3, (MOD - 1) / (2 * half));
        int iw = power(w, MOD - 2);
        roots[half] = inverseRoots[half] = 1;
        for (int j = 1; j < half; ++j) {
            roots[half + j] = 1LL * roots[half + j - 1] * w % MOD;
            inverseRoots[half + j] = 1LL * inverseRoots[half + j - 1] * iw % MOD;
        }
    }
    if (!inverse) {
        for (int half = n / 2; half; half >>= 1)
            for (int start = 0; start < n; start += 2 * half)
                for (int j = 0; j < half; ++j) {
                    int u = a[start + j], v = a[start + j + half];
                    int sum = u + v, difference = u - v;
                    if (sum >= MOD) sum -= MOD;
                    if (difference < 0) difference += MOD;
                    a[start + j] = sum;
                    a[start + j + half] = 1LL * difference * roots[half + j] % MOD;
                }
    } else {
        for (int half = 1; half < n; half <<= 1)
            for (int start = 0; start < n; start += 2 * half)
                for (int j = 0; j < half; ++j) {
                    int u = a[start + j];
                    int v = 1LL * a[start + j + half] * inverseRoots[half + j] % MOD;
                    int sum = u + v, difference = u - v;
                    if (sum >= MOD) sum -= MOD;
                    if (difference < 0) difference += MOD;
                    a[start + j] = sum;
                    a[start + j + half] = difference;
                }
        int scale = power(n, MOD - 2);
        for (int &x : a) x = 1LL * x * scale % MOD;
    }
}
Polynomial multiply(Polynomial a, Polynomial b) {
    if (a.empty() || b.empty()) return {};
    int size = int(a.size() + b.size()) - 1;
    if (min(a.size(), b.size()) <= 32) {
        Polynomial c(size);
        for (int i = 0; i < int(a.size()); ++i)
            for (int j = 0; j < int(b.size()); ++j)
                c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % MOD;
        return c;
    }
    int n = transformSize(size);
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * b[i] % MOD;
    ntt(a, true);
    a.resize(size);
    return a;
}

Polynomial inverse(const Polynomial &a, int size) {
    Polynomial b{power(a[0], MOD - 2)};
    while (int(b.size()) < size) {
        int old = int(b.size()), n = 2 * old;
        Polynomial fb = b, error(n);
        fb.resize(n);
        copy_n(a.begin(), min(n, int(a.size())), error.begin());
        ntt(fb, false);
        ntt(error, false);
        for (int i = 0; i < n; ++i) error[i] = 1LL * error[i] * fb[i] % MOD;
        ntt(error, true);
        // Only the upper half is needed. Cyclic wraparound affects the lower half.
        fill(error.begin(), error.begin() + old, 0);
        ntt(error, false);
        for (int i = 0; i < n; ++i) error[i] = 1LL * error[i] * fb[i] % MOD;
        ntt(error, true);
        b.resize(n);
        for (int i = old; i < n; ++i) b[i] = error[i] ? MOD - error[i] : 0;
    }
    b.resize(size);
    return b;
}

class Remainder {
    int m, n;
    Polynomial characteristic, inversePrefix, transformedP, transformedInverse;
public:
    explicit Remainder(const Polynomial &c)
        : m(int(c.size()) - 1), n(transformSize(2 * m - 1)),
          characteristic(c.rbegin(), c.rend()), inversePrefix(inverse(c, m)) {}

    Polynomial square(const Polynomial &a) {
        int size = 2 * int(a.size()) - 1;
        Polynomial product;
        if (int(a.size()) <= 32) {
            product = multiply(a, a);
        } else {
            product = a;
            product.resize(transformSize(size));
            ntt(product, false);
            for (int &x : product) x = 1LL * x * x % MOD;
            ntt(product, true);
            product.resize(size);
        }
        if (size <= m) return product;
        int length = size - m;
        Polynomial quotient(product.rbegin(), product.rbegin() + length);
        if (length < m - 1 || m <= 32) {
            Polynomial cut(inversePrefix.begin(), inversePrefix.begin() + length);
            quotient = multiply(quotient, cut);
            quotient.resize(length);
            reverse(quotient.begin(), quotient.end());
            auto removed = multiply(quotient, characteristic);
            product.resize(m);
            for (int i = 0; i < m; ++i) {
                product[i] -= removed[i];
                if (product[i] < 0) product[i] += MOD;
            }
        } else {
            if (transformedP.empty()) {
                transformedP = characteristic;
                transformedP.resize(n);
                transformedInverse = inversePrefix;
                transformedInverse.resize(n);
                ntt(transformedP, false);
                ntt(transformedInverse, false);
            }
            quotient.resize(n);
            ntt(quotient, false);
            for (int i = 0; i < n; ++i)
                quotient[i] = 1LL * quotient[i] * transformedInverse[i] % MOD;
            ntt(quotient, true);
            quotient.resize(length);
            reverse(quotient.begin(), quotient.end());
            quotient.resize(n);
            ntt(quotient, false);
            for (int i = 0; i < n; ++i)
                quotient[i] = 1LL * quotient[i] * transformedP[i] % MOD;
            ntt(quotient, true);
            product.resize(m);
            for (int i = 0; i < m; ++i) {
                product[i] -= quotient[i];
                if (product[i] < 0) product[i] += MOD;
            }
        }
        return product;
    }

    void multiplyX(Polynomial &a) const {
        if (int(a.size()) < m) {
            a.insert(a.begin(), 0);
            return;
        }
        int top = a.back();
        for (int i = m - 1; i >= 0; --i) {
            int value = i ? a[i - 1] : 0;
            value = (value - 1LL * top * characteristic[i]) % MOD;
            if (value < 0) value += MOD;
            a[i] = value;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    long long l, r;
    if (!(cin >> m >> l >> r)) return 0;
    int count = int(r - l + 1);
    Polynomial c(m + 1);
    c[0] = 1;
    for (int i = 1, k; i <= m; ++i) {
        cin >> k;
        c[i] = k ? MOD - k : 0;
    }
    if (m == 1) {
        int k = c[1] ? MOD - c[1] : 0, a = power(k, l);
        for (int i = 0; i < count; ++i, a = 1LL * a * k % MOD) cout << a << '\n';
        return 0;
    }
    Polynomial result{1};
    if (l) {
        Remainder reduce(c);
        int highest = 0;
        while ((1LL << (highest + 1)) <= l) ++highest;
        for (int bit = highest; bit >= 0; --bit) {
            result = reduce.square(result);
            if ((l >> bit) & 1) reduce.multiplyX(result);
        }
    }
    int used = int(result.size());
    auto prefix = inverse(c, used + count - 1);
    reverse(result.begin(), result.end());
    auto answer = multiply(result, prefix);
    for (int i = 0; i < count; ++i) cout << answer[used - 1 + i] << '\n';
}
