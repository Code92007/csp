#include <array>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using Bits = bitset<1001>;
using Poly = bitset<2048>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<Bits> a(m), basis(m), expression(m), states;
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j)
            a[i][j] = s[j] == '1';
    }
    cin >> s;
    Bits current;
    for (int j = 0; j < m; ++j)
        current[j] = s[j] == '1';
    Poly relation;
    int degree = 0;
    for (int d = 0; d <= m; ++d) {
        Bits v = current, e;
        e[d] = 1;
        bool independent = false;
        for (int p = m - 1; p >= 0; --p)
            if (v[p]) {
                if (basis[p].none()) {
                    basis[p] = v;
                    expression[p] = e;
                    independent = true;
                    break;
                }
                v ^= basis[p];
                e ^= expression[p];
            }
        if (!independent) {
            degree = d;
            for (int j = 0; j <= d; ++j)
                relation[j] = e[j];
            break;
        }
        states.push_back(current);
        Bits next;
        for (int i = 0; i < m; ++i)
            next[i] = (a[i] & current).count() % 2;
        current = next;
    }
    auto reduce = [&](Poly v) {
        for (int i = 2 * degree - 1; i >= degree; --i)
            if (v[i])
                v ^= relation << (i - degree);
        return v;
    };
    auto multiply = [&](const Poly &x, const Poly &y) {
        Poly z;
        for (int i = 0; i < degree; ++i)
            if (x[i])
                z ^= y << i;
        return reduce(z);
    };
    array<Poly, 31> power{};
    if (degree) {
        power[0][1] = 1;
        power[0] = reduce(power[0]);
        for (int j = 1; j < 31; ++j)
            power[j] = multiply(power[j - 1], power[j - 1]);
    }
    int q;
    cin >> q;
    while (q--) {
        unsigned k;
        cin >> k;
        Bits answer;
        if (degree) {
            Poly p;
            p[0] = 1;
            for (int j = 0; j < 31; ++j)
                if (k >> j & 1)
                    p = multiply(p, power[j]);
            for (int j = 0; j < degree; ++j)
                if (p[j])
                    answer ^= states[j];
        }
        for (int j = 0; j < m; ++j)
            cout << answer[j];
        cout << '\n';
    }
}
