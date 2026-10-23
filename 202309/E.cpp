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
        ll weight = 0;
        multiset<ll> sideFirst, sideBest;
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
        ll first = 0, second = 0;
        auto it = t[u].sideFirst.rbegin();
        if (it != t[u].sideFirst.rend()) {
            first = max(0LL, *it);
            ++it;
        }
        if (it != t[u].sideFirst.rend())
            second = max(0LL, *it);
        ll w = t[u].weight, b = t[u].sideBest.empty() ? NEG : *t[u].sideBest.rbegin();
        return {w, w + first, w + first, max(b, w + first + second)};
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
        t[u].sideFirst.insert(t[v].data.first);
        t[u].sideBest.insert(t[v].data.best);
    }
    void virtualRemove(int u, int v) {
        if (!v)
            return;
        t[u].sideFirst.erase(t[u].sideFirst.find(t[v].data.first));
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
    DynamicTree dt(2 * n);
    vector<long long> loss(n);
    for (int i = 1; i <= n; ++i)
        dt.pull(i);
    for (int i = 1; i < n; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w >> loss[i];
        int node = n + i;
        dt.t[node].weight = loss[i] - w;
        dt.pull(node);
        dt.link(u, node);
        dt.link(node, v);
    }
    cout << max(0LL, dt.subtreeBest(1, 1)) << '\n';
    while (m--) {
        int edge;
        long long value;
        cin >> edge >> value;
        dt.setWeight(n + edge, loss[edge] - value);
        cout << max(0LL, dt.subtreeBest(1, 1)) << '\n';
    }
}
