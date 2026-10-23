#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

struct ParityDSU {
    vector<int> parent, size, parity;
    explicit ParityDSU(int n) : parent(n), size(n, 1), parity(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        int old = parent[x];
        parent[x] = find(old);
        parity[x] ^= parity[old];
        return parent[x];
    }
    bool join(int a, int b, int difference) {
        int ra = find(a), rb = find(b);
        int relation = parity[a] ^ parity[b] ^ difference;
        if (ra == rb) return relation == 0;
        if (size[ra] < size[rb]) swap(ra, rb);
        parent[rb] = ra;
        parity[rb] = relation;
        size[ra] += size[rb];
        return true;
    }
};

struct Successor {
    vector<int> parent;
    explicit Successor(int n) : parent(n + 1) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) {
        int root = x;
        while (parent[root] != root) root = parent[root];
        while (parent[x] != x) { int next = parent[x]; parent[x] = root; x = next; }
        return root;
    }
    void erase(int x) { parent[x] = find(x + 1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, op;
    ll k;
    if (!(cin >> n >> k >> op)) return 0;
    vector<ll> values(n);
    for (ll& x : values) cin >> x;
    sort(values.begin(), values.end());
    ParityDSU dsu(n);
    Successor unused(n);
    bool hasEdge = false, bipartite = true;
    for (int i = 0; i < n && bipartite; ++i) {
        if (op == 0) {
            if (values[i] % k != 0) continue;
            auto it = lower_bound(values.begin(), values.end(), values[i] / k);
            if (it != values.end() && *it == values[i] / k) {
                hasEdge = true;
                bipartite = dsu.join(i, int(it - values.begin()), 1);
            }
        } else {
            int left = upper_bound(values.begin(), values.end(), values[i] / (k + 1)) - values.begin();
            int right = int(upper_bound(values.begin(), values.end(), values[i] / k) - values.begin()) - 1;
            if (left > right) continue;
            hasEdge = true;
            // All smaller neighbours of i must have the same colour.
            for (int j = unused.find(left); j < right; j = unused.find(j)) {
                if (!dsu.join(j, j + 1, 0)) { bipartite = false; break; }
                unused.erase(j);
            }
            if (bipartite) bipartite = dsu.join(i, left, 1);
        }
    }
    int groupCount = !hasEdge ? 1 : (bipartite ? 2 : 3);
    vector<vector<ll>> groups(groupCount);
    for (int i = 0; i < n; ++i) {
        int colour = 0;
        if (groupCount == 2) {
            dsu.find(i);
            colour = dsu.parity[i];
        } else if (groupCount == 3) {
            ll x = values[i];
            int level = 0;
            while (x >= k) { x /= k; ++level; }
            colour = level % 3;
        }
        groups[colour].push_back(values[i]);
    }
    cout << groupCount << '\n';
    for (const auto& group : groups) {
        cout << group.size();
        for (ll x : group) cout << ' ' << x;
        cout << '\n';
    }
}
