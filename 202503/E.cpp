#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
const ll NEG = -(1LL << 60);
struct Summary {
    ll sum = 0, first = NEG, last = NEG, best = NEG;
};
Summary join(Summary a, Summary b) {
    return {a.sum + b.sum, max(a.first, a.sum + b.first), max(b.last, b.sum + a.last),
            max({a.best, b.best, a.last + b.first})};
}
struct DynamicTree {
    struct Node {
        int child[2]{}, parent = 0;
        bool reverse = false;
        ll weight = 0, sideSum = 0;
        multiset<ll> sideBest;
        Summary data;
    };
    vector<Node> t;
    vector<int> path;
    explicit DynamicTree(int n) : t(n + 1) {
        path.reserve(n);
    }
    bool auxiliaryRoot(int u) {
        int p = t[u].parent;
        return t[p].child[0] != u && t[p].child[1] != u;
    }
    Summary local(int u) {
        ll x = t[u].weight + t[u].sideSum;
        ll y = t[u].sideBest.empty() ? NEG : *t[u].sideBest.rbegin();
        return {x, x, x, max(x, y)};
    }
    void pull(int u) {
        t[u].data = join(join(t[t[u].child[0]].data, local(u)), t[t[u].child[1]].data);
    }
    void flip(int u) {
        if (!u)
            return;
        swap(t[u].child[0], t[u].child[1]);
        swap(t[u].data.first, t[u].data.last);
        t[u].reverse ^= 1;
    }
    void push(int u) {
        if (t[u].reverse) {
            flip(t[u].child[0]);
            flip(t[u].child[1]);
            t[u].reverse = false;
        }
    }
    void rotate(int u) {
        int p = t[u].parent, g = t[p].parent, d = t[p].child[1] == u, v = t[u].child[d ^ 1];
        if (!auxiliaryRoot(p))
            t[g].child[t[g].child[1] == p] = u;
        t[u].parent = g;
        t[u].child[d ^ 1] = p;
        t[p].parent = u;
        t[p].child[d] = v;
        if (v)
            t[v].parent = p;
        pull(p);
        pull(u);
    }
    void splay(int u) {
        path.clear();
        int v = u;
        path.push_back(v);
        while (!auxiliaryRoot(v)) {
            v = t[v].parent;
            path.push_back(v);
        }
        for (auto it = path.rbegin(); it != path.rend(); ++it)
            push(*it);
        while (!auxiliaryRoot(u)) {
            int p = t[u].parent, g = t[p].parent;
            if (!auxiliaryRoot(p))
                rotate((t[p].child[1] == u) == (t[g].child[1] == p) ? p : u);
            rotate(u);
        }
    }
    void virtualAdd(int u, int v) {
        if (!v)
            return;
        t[u].sideSum += max(0LL, t[v].data.first);
        t[u].sideBest.insert(t[v].data.best);
    }
    void virtualRemove(int u, int v) {
        if (!v)
            return;
        t[u].sideSum -= max(0LL, t[v].data.first);
        auto it = t[u].sideBest.find(t[v].data.best);
        t[u].sideBest.erase(it);
    }
    void access(int u) {
        for (int v = 0, x = u; x; v = x, x = t[x].parent) {
            splay(x);
            virtualAdd(x, t[x].child[1]);
            virtualRemove(x, v);
            t[x].child[1] = v;
            pull(x);
        }
        splay(u);
    }
    void makeRoot(int u) {
        access(u);
        flip(u);
    }
    void link(int u, int v) {
        makeRoot(u);
        access(v);
        t[u].parent = v;
        virtualAdd(v, u);
        pull(v);
    }
    void cut(int u, int v) {
        makeRoot(u);
        access(v);
        t[v].child[0] = 0;
        t[u].parent = 0;
        pull(v);
    }
    void setWeight(int u, ll w) {
        access(u);
        t[u].weight = w;
        pull(u);
    }
    ll rootedValue(int root) {
        makeRoot(root);
        access(root);
        return local(root).first;
    }
    ll subtreeBest(int root, int u) {
        makeRoot(root);
        access(u);
        return local(u).best;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DynamicTree dt(n);
    for (int i = 1; i <= n; ++i) {
        cin >> dt.t[i].weight;
        dt.pull(i);
    }
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        dt.link(u, v);
    }
    int root = 1;
    cout << dt.rootedValue(root) << '\n';
    while (m--) {
        int op, u;
        cin >> op >> u;
        if (op == 1) {
            cout << dt.subtreeBest(root, u) << '\n';
            continue;
        }
        if (op == 2) {
            ll x;
            cin >> x;
            dt.setWeight(u, x);
        }
        if (op == 3)
            root = u;
        if (op == 4) {
            int v, c, d;
            cin >> v >> c >> d;
            dt.cut(u, v);
            dt.link(c, d);
        }
        cout << dt.rootedValue(root) << '\n';
    }
}
