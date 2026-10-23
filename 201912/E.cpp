#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using U = uint64_t;
using Wide = __uint128_t;
const U MOD = 2009731336725594113ULL;
const U magic[5] = {314882150829468584ULL, 427197303358170108ULL, 1022292690726729920ULL,
                    1698479428772363217ULL, 2006101093849356424ULL};
int product[32][32];
struct Tree {
    int base;
    vector<array<int, 32>> sum;
    vector<unsigned char> lazy;
    explicit Tree(int n, const vector<U> &group) {
        base = 1;
        while (base < n)
            base *= 2;
        sum.resize(2 * base);
        lazy.resize(2 * base);
        array<U, 32> residue{};
        for (int i = 1; i <= n; ++i)
            for (int s = 0; s < 32; ++s) {
                residue[s] += group[s];
                if (residue[s] >= MOD)
                    residue[s] -= MOD;
                sum[base + i - 1][s] = residue[s] % 2019;
            }
        for (int u = base - 1; u; --u)
            pull(u);
    }
    void pull(int u) {
        for (int s = 0; s < 32; ++s)
            sum[u][s] = sum[2 * u][s] + sum[2 * u + 1][s];
    }
    void apply(int u, int state) {
        array<int, 32> next;
        for (int s = 0; s < 32; ++s)
            next[s] = sum[u][product[s][state]];
        sum[u] = next;
        lazy[u] = product[lazy[u]][state];
    }
    void push(int u) {
        if (lazy[u]) {
            apply(2 * u, lazy[u]);
            apply(2 * u + 1, lazy[u]);
            lazy[u] = 0;
        }
    }
    int query(int u, int l, int r, int a, int b) {
        if (a <= l && r <= b)
            return sum[u][0];
        push(u);
        int mid = (l + r) / 2, ans = 0;
        if (a <= mid)
            ans += query(2 * u, l, mid, a, b);
        if (b > mid)
            ans += query(2 * u + 1, mid + 1, r, a, b);
        return ans;
    }
    void update(int u, int l, int r, int a, int b, int state) {
        if (a <= l && r <= b) {
            apply(u, state);
            return;
        }
        push(u);
        int mid = (l + r) / 2;
        if (a <= mid)
            update(2 * u, l, mid, a, b, state);
        if (b > mid)
            update(2 * u + 1, mid + 1, r, a, b, state);
        pull(u);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<U> group{1};
    map<U, int> id{{1, 0}};
    for (size_t i = 0; i < group.size(); ++i)
        for (U x : magic) {
            U y = Wide(group[i]) * x % MOD;
            if (!id.count(y)) {
                id[y] = group.size();
                group.push_back(y);
            }
        }
    if (group.size() != 32)
        return 1;
    for (int i = 0; i < 32; ++i)
        for (int j = 0; j < 32; ++j)
            product[i][j] = id.at(Wide(group[i]) * group[j] % MOD);
    Tree tree(n, group);
    while (q--) {
        int l, r;
        cin >> l >> r;
        int answer = tree.query(1, 1, tree.base, l, r);
        cout << answer << '\n';
        tree.update(1, 1, tree.base, l, r, id.at(magic[answer % 5]));
    }
}
