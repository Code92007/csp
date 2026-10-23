#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// At each lower-bit node, two sides are internally cliques.
struct Node {
    int child[2]{}, count[2]{}, best = 0;
};
vector<Node> trie(1);
int highest, threshold;
int fresh() {
    trie.emplace_back();
    return int(trie.size()) - 1;
}
void pull(int u, int bit) {
    int l = trie[u].child[0], r = trie[u].child[1];
    if (bit >= highest)
        trie[u].best = max(trie[l].best, trie[r].best);
    else if (bit >= 0 && (threshold >> bit & 1))
        trie[u].best = trie[l].best + trie[r].best;
    else
        trie[u].best = max({trie[u].count[0], trie[u].count[1], trie[l].best, trie[r].best});
}
int insert(int u, unsigned key, int side, int bit) {
    if (!u)
        u = fresh();
    ++trie[u].count[side];
    if (bit >= 0) {
        int c = key >> bit & 1;
        // Do not keep references into vector across a possible reallocation.
        int v = insert(trie[u].child[c], key, side, bit - 1);
        trie[u].child[c] = v;
    }
    pull(u, bit);
    return u;
}
int mergeTree(int u, int v, int bit) {
    if (!u || !v)
        return u | v;
    for (int s = 0; s < 2; ++s)
        trie[u].count[s] += trie[v].count[s];
    if (bit >= 0)
        for (int c = 0; c < 2; ++c)
            trie[u].child[c] = mergeTree(trie[u].child[c], trie[v].child[c], bit - 1);
    pull(u, bit);
    return u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long W;
    if (!(cin >> n >> W))
        return 0;
    vector<int> roots(n + 1), sizes(n + 1);
    // All input values are below 2^30.
    bool allConflict = W >= (1LL << 30);
    highest = 0;
    while ((1LL << (highest + 1)) <= W && highest < 30)
        ++highest;
    threshold = int(W - (1LL << highest));
    auto add = [&](int u, unsigned x) {
        ++sizes[u];
        if (allConflict)
            return;
        int side = x >> highest & 1;
        unsigned low = x & ((1u << highest) - 1);
        if (side)
            low ^= threshold;
        unsigned key = ((x >> (highest + 1)) << highest) | low;
        roots[u] = insert(roots[u], key, side, 28);
    };
    auto value = [&](int u) { return allConflict ? sizes[u] : trie[roots[u]].best; };
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        while (m--) {
            unsigned x;
            cin >> x;
            add(i, x);
        }
        total += value(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u;
            unsigned x;
            cin >> u >> x;
            total -= value(u);
            add(u, x);
            total += value(u);
        } else if (op == 2) {
            int u, v;
            cin >> u >> v;
            total -= value(u) + value(v);
            sizes[u] += sizes[v];
            sizes[v] = 0;
            if (!allConflict)
                roots[u] = mergeTree(roots[u], roots[v], 28);
            roots[v] = 0;
            total += value(u);
        } else
            cout << total << '\n';
    }
}
