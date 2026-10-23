#include <array>
#include <iostream>
#include <vector>
using namespace std;
using i64 = long long;
constexpr int DIGITS = 12;
struct Node {
    array<i64, DIGITS> sum{}, product{}, lazy{};
};
int n, q, digits, base;
i64 mod;
vector<Node> tree;
array<i64, DIGITS> split(i64 x) {
    array<i64, DIGITS> a{};
    for (int j = 0; j < digits; ++j) {
        a[j] = x % mod;
        x /= mod;
    }
    return a;
}
void pull(int u) {
    for (int j = 0; j < digits; ++j) {
        tree[u].sum[j] = (tree[u * 2].sum[j] + tree[u * 2 + 1].sum[j]) % mod;
        tree[u].product[j] = (tree[u * 2].product[j] + tree[u * 2 + 1].product[j]) % mod;
    }
}
void apply(int u, int len, const array<i64, DIGITS> &shift) {
    Node &t = tree[u];
    // product[0] is the sum of squares. Preserve all old sums until products are updated.
    for (int j = 0; j < digits; ++j) {
        t.product[j] = (t.product[j] + shift[0] * t.sum[j] + shift[j] * t.sum[0] +
                        (shift[0] * shift[j] % mod) * len) %
                       mod;
    }
    for (int j = 0; j < digits; ++j) {
        t.sum[j] = (t.sum[j] + shift[j] * len) % mod;
        t.lazy[j] = (t.lazy[j] + shift[j]) % mod;
    }
}
void push(int u, int len) {
    bool any = false;
    for (int j = 0; j < digits; ++j)
        any |= tree[u].lazy[j] != 0;
    if (!any)
        return;
    apply(u * 2, len / 2, tree[u].lazy);
    apply(u * 2 + 1, len / 2, tree[u].lazy);
    tree[u].lazy.fill(0);
}
void update(int u, int l, int r, int a, int b, const array<i64, DIGITS> &shift) {
    if (a <= l && r <= b) {
        apply(u, r - l + 1, shift);
        return;
    }
    push(u, r - l + 1);
    int mid = (l + r) / 2;
    if (a <= mid)
        update(u * 2, l, mid, a, b, shift);
    if (b > mid)
        update(u * 2 + 1, mid + 1, r, a, b, shift);
    pull(u);
}
void query(int u, int l, int r, int a, int b, array<i64, DIGITS> &result) {
    if (a <= l && r <= b) {
        for (int j = 0; j < digits; ++j)
            result[j] = (result[j] + tree[u].sum[j] + tree[u].product[j]) % mod;
        return;
    }
    push(u, r - l + 1);
    int mid = (l + r) / 2;
    if (a <= mid)
        query(u * 2, l, mid, a, b, result);
    if (b > mid)
        query(u * 2 + 1, mid + 1, r, a, b, result);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q >> mod;
    for (i64 x = 1000000000000LL; x; x /= mod)
        ++digits;
    base = 1;
    while (base < n)
        base *= 2;
    tree.resize(base * 2);
    for (int i = 0; i < n; ++i) {
        i64 x;
        cin >> x;
        auto a = split(x);
        tree[base + i].sum = a;
        for (int j = 0; j < digits; ++j)
            tree[base + i].product[j] = a[0] * a[j] % mod;
    }
    for (int u = base - 1; u; --u)
        pull(u);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            i64 v;
            cin >> v;
            update(1, 1, base, l, r, split(v));
        } else {
            array<i64, DIGITS> ans{};
            query(1, 1, base, l, r, ans);
            ans[0] = ans[0] * ((mod + 1) / 2) % mod;
            i64 value = 0;
            for (int j = digits - 1; j >= 0; --j)
                value = value * mod + ans[j];
            cout << value << '\n';
        }
    }
}
