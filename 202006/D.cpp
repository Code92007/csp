#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using i64 = long long;
constexpr i64 MOD = 998244353;
using Matrix = array<array<i64, 5>, 5>;
using Vector = array<i64, 5>;
Matrix identity() {
    Matrix a{};
    for (int i = 0; i < 5; ++i)
        a[i][i] = 1;
    return a;
}
Matrix multiply(const Matrix &a, const Matrix &b) {
    Matrix c{};
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            for (int k = 0; k < 5; ++k)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    return c;
}
Vector apply_matrix(const Matrix &a, const Vector &b) {
    Vector c{};
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            c[i] = (c[i] + a[i][j] * b[j]) % MOD;
    return c;
}
struct Ends {
    array<string, 4> prefix, suffix;
    bool operator==(const Ends &b) const {
        return prefix == b.prefix && suffix == b.suffix;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n;
    string pattern;
    cin >> n >> pattern;
    int length = pattern.size(), keep = length - 1;
    vector<int> failure(length);
    for (int i = 1, j = 0; i < length; ++i) {
        while (j && pattern[i] != pattern[j])
            j = failure[j - 1];
        if (pattern[i] == pattern[j])
            ++j;
        failure[i] = j;
    }
    auto matches = [&](const string &text) {
        i64 count = 0;
        int j = 0;
        for (char c : text) {
            while (j && c != pattern[j])
                j = failure[j - 1];
            if (c == pattern[j])
                ++j;
            if (j == length) {
                ++count;
                j = failure[j - 1];
            }
        }
        return count;
    };
    const string symbols = "1246";
    const vector<vector<int>> children{{1}, {2}, {0, 3}, {3, 2}};
    Ends state;
    Vector count{};
    count[4] = 1;
    for (int a = 0; a < 4; ++a) {
        if (keep)
            state.prefix[a] = state.suffix[a] = string(1, symbols[a]);
        count[a] = pattern == string(1, symbols[a]);
    }
    deque<Ends> history{state};
    vector<Matrix> transitions;
    for (i64 time = 0; time < n;) {
        Ends next;
        Matrix transform{};
        transform[4][4] = 1;
        for (int a = 0; a < 4; ++a) {
            for (int child : children[a]) {
                ++transform[a][child];
                next.prefix[a] += state.prefix[child];
                next.suffix[a] += state.suffix[child];
            }
            if (int(next.prefix[a].size()) > keep)
                next.prefix[a].resize(keep);
            if (int(next.suffix[a].size()) > keep)
                next.suffix[a].erase(0, next.suffix[a].size() - keep);
            if (children[a].size() == 2)
                transform[a][4] =
                    matches(state.suffix[children[a][0]] + state.prefix[children[a][1]]);
        }
        count = apply_matrix(transform, count);
        state = std::move(next);
        transitions.push_back(transform);
        ++time;
        // Equal endpoints imply exactly equal future boundary contributions.
        if (history.size() == 6 && state == history.front()) {
            i64 remaining = n - time;
            int begin = int(transitions.size()) - 6;
            Matrix cycle = identity();
            for (int j = begin; j < begin + 6; ++j)
                cycle = multiply(transitions[j], cycle);
            i64 rounds = remaining / 6;
            while (rounds) {
                if (rounds & 1)
                    count = apply_matrix(cycle, count);
                cycle = multiply(cycle, cycle);
                rounds /= 2;
            }
            for (int j = 0; j < remaining % 6; ++j)
                count = apply_matrix(transitions[begin + j], count);
            break;
        }
        history.push_back(state);
        if (history.size() > 6)
            history.pop_front();
    }
    cout << count[0] << '\n';
}
