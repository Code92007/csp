#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
constexpr int MOD = 998244353, S = 10, SMALL = 100000;
using Row = array<int, S>;
using Matrix = array<Row, S>;
Row multiply(const Row &a, const Matrix &b) {
    Row c{};
    for (int j = 0; j < S; ++j) {
        uint64_t sum = 0;
        for (int k = 0; k < S; ++k)
            sum += uint64_t(a[k]) * b[k][j];
        c[j] = sum % MOD;
    }
    return c;
}
int next_state(int s, char ch) {
    if (s == 9)
        return 9;
    string pattern = s < 3 ? "ccf" : "cspark";
    int offset = s < 3 ? 0 : 3;
    string text = pattern.substr(0, s - offset) + ch;
    for (int len = pattern.size(); len >= 0; --len)
        if (text.size() >= size_t(len) &&
            text.compare(text.size() - len, len, pattern, 0, len) == 0)
            return offset + len;
    return offset;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> lengths;
    int previous = 0;
    for (int i = 0; i < m; ++i) {
        int position;
        cin >> position;
        lengths.push_back(position - previous - 1);
        previous = position;
    }
    lengths.push_back(n - previous);
    Matrix transition{};
    for (int s = 0; s < S; ++s)
        for (char c = 'a'; c <= 'z'; ++c)
            ++transition[s][next_state(s, c)];
    array<Matrix, 30> power;
    power[0] = transition;
    for (int bit = 1; bit < 30; ++bit)
        for (int row = 0; row < S; ++row)
            power[bit][row] = multiply(power[bit - 1][row], power[bit - 1]);
    // For a segment: counts for 0->0, 0->1, 1->1, and all strings.
    auto extract = [](const Row &a, const Row &b) {
        array<int, 4> result{};
        for (int s = 0; s < S; ++s) {
            if (s < 3)
                result[0] = (result[0] + a[s]) % MOD;
            if (s >= 3 && s < 9)
                result[1] = (result[1] + a[s]) % MOD;
            if (s < 9)
                result[2] = (result[2] + b[s]) % MOD;
            result[3] = (result[3] + a[s]) % MOD;
        }
        return result;
    };
    vector<array<int, 4>> small(min(n, SMALL) + 1);
    Row a{}, b{};
    a[0] = b[3] = 1;
    for (size_t len = 0; len < small.size(); ++len) {
        small[len] = extract(a, b);
        a = multiply(a, transition);
        b = multiply(b, transition);
    }
    unordered_map<int, array<int, 4>> cache;
    long long unseen = 1, waiting = 0, accepted = 0;
    for (int len : lengths) {
        array<int, 4> ways;
        if (len < int(small.size()))
            ways = small[len];
        else if (cache.count(len))
            ways = cache[len];
        else {
            a.fill(0);
            b.fill(0);
            a[0] = b[3] = 1;
            for (int bit = 0; bit < 30; ++bit)
                if (len >> bit & 1) {
                    a = multiply(a, power[bit]);
                    b = multiply(b, power[bit]);
                }
            ways = cache[len] = extract(a, b);
        }
        auto [no_first, first_only, no_second, all] = ways;
        long long direct = (all - no_first - first_only + 2LL * MOD) % MOD;
        accepted = (accepted * all + waiting * (all - no_second + MOD) + unseen * direct) % MOD;
        waiting = (waiting * no_second + unseen * first_only) % MOD;
        unseen = unseen * no_first % MOD;
    }
    cout << accepted << '\n';
}
