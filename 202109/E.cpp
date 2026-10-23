#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
struct LCT {
    struct Node {
        int child[2]{}, parent = 0;
        ll value = 0, sum = 0, mul = 1;
        bool rev = false;
    };
    vector<Node> t;
    vector<int> stack;
    ll mod;
    LCT(int n, ll p) : t(n + 1), mod(p) {
        stack.reserve(n);
    }
    bool isRoot(int x) {
        int p = t[x].parent;
        return t[p].child[0] != x && t[p].child[1] != x;
    }
    void pull(int x) {
        t[x].sum = (t[x].value + t[t[x].child[0]].sum + t[t[x].child[1]].sum) % mod;
    }
    void multiply(int x, ll v) {
        if (!x)
            return;
        t[x].value = t[x].value * v % mod;
        t[x].sum = t[x].sum * v % mod;
        t[x].mul = t[x].mul * v % mod;
    }
    void flip(int x) {
        if (x) {
            swap(t[x].child[0], t[x].child[1]);
            t[x].rev ^= 1;
        }
    }
    void push(int x) {
        if (t[x].rev) {
            flip(t[x].child[0]);
            flip(t[x].child[1]);
            t[x].rev = false;
        }
        if (t[x].mul != 1) {
            multiply(t[x].child[0], t[x].mul);
            multiply(t[x].child[1], t[x].mul);
            t[x].mul = 1;
        }
    }
    void rotate(int x) {
        int p = t[x].parent, g = t[p].parent, d = t[p].child[1] == x, v = t[x].child[d ^ 1];
        if (!isRoot(p))
            t[g].child[t[g].child[1] == p] = x;
        t[x].parent = g;
        t[x].child[d ^ 1] = p;
        t[p].parent = x;
        t[p].child[d] = v;
        if (v)
            t[v].parent = p;
        pull(p);
        pull(x);
    }
    void splay(int x) {
        stack.clear();
        int y = x;
        stack.push_back(y);
        while (!isRoot(y)) {
            y = t[y].parent;
            stack.push_back(y);
        }
        for (auto it = stack.rbegin(); it != stack.rend(); ++it)
            push(*it);
        while (!isRoot(x)) {
            int p = t[x].parent, g = t[p].parent;
            if (!isRoot(p))
                rotate((t[p].child[1] == x) == (t[g].child[1] == p) ? p : x);
            rotate(x);
        }
    }
    void access(int x) {
        for (int y = 0, u = x; u; y = u, u = t[u].parent) {
            splay(u);
            t[u].child[1] = y;
            pull(u);
        }
        splay(x);
    }
    void path(int u, int v) {
        access(u);
        flip(u);
        access(v);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, mod, T;
    cin >> m >> mod >> T;
    LCT tree(m, mod);
    vector<array<int, 20>> up(m + 1);
    vector<int> depth(m + 1), tail(m + 1);
    int current = 0, count = 0, last = 0;
    auto atDepth = [&](int u, int d) {
        int step = depth[u] - d;
        for (int b = 0; b < 20; ++b)
            if (step >> b & 1)
                u = up[u][b];
        return u;
    };
    for (int day = 1; day <= m; ++day) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            x ^= T * last;
            if (!x)
                current = up[current][0];
            else {
                int u = ++count;
                up[u][0] = current;
                depth[u] = depth[current] + 1;
                for (int b = 1; b < 20; ++b)
                    up[u][b] = up[up[u][b - 1]][b - 1];
                tree.t[u].value = tree.t[u].sum = x % mod;
                tree.t[u].parent = current;
                current = u;
            }
        } else {
            int s, l, r;
            cin >> s >> l >> r;
            int endpoint = s == day ? current : tail[s];
            int u = atDepth(endpoint, l), v = atDepth(endpoint, r);
            tree.path(u, v);
            if (op == 2) {
                int y;
                cin >> y;
                y ^= T * last;
                tree.multiply(v, y % mod);
            } else {
                last = tree.t[v].sum;
                cout << last << '\n';
            }
        }
        tail[day] = current;
    }
}
