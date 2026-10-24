#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using Mask = uint64_t;
using ll = long long;

struct Hash {
    size_t operator()(Mask x) const {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
};
class Counter {
    static constexpr Mask empty = ~Mask(0);
    vector<Mask> keys;
    vector<int> values;
    size_t capacityMask = 0;

    size_t slot(Mask key) const {
        size_t i = Hash{}(key) & capacityMask;
        while (keys[i] != empty && keys[i] != key) i = (i + 1) & capacityMask;
        return i;
    }
public:
    void reserve(size_t expected) {
        size_t capacity = 2;
        while (capacity < expected * 2) capacity <<= 1;
        keys.assign(capacity, empty);
        values.assign(capacity, 0);
        capacityMask = capacity - 1;
    }
    void emplace(Mask key, int value) {
        size_t i = slot(key);
        if (keys[i] == empty) { keys[i] = key; values[i] = value; }
    }
    int get(Mask key) const {
        size_t i = slot(key);
        return keys[i] == key ? values[i] : 0;
    }
    void add(Mask key, int delta) { values[slot(key)] += delta; }
};
struct Edge { int to, weight; };
struct Record { Mask mask; int centre, branch, distance; };
struct Visit { int node, parent, distance; Mask mask; };

class Solver {
    int n, modulus;
    vector<vector<Edge>> tree;
    vector<Mask> bit, colours;
    vector<bool> removed;
    vector<int> parent, subtree;
    vector<vector<Record>> ancestors;
    vector<Counter> all, branch;

    int centroid(int start, vector<int>& nodes) {
        nodes.push_back(start);
        parent[start] = -1;
        for (size_t i = 0; i < nodes.size(); ++i) {
            int v = nodes[i];
            for (const auto& e : tree[v]) {
                if (removed[e.to] || e.to == parent[v]) continue;
                parent[e.to] = v;
                nodes.push_back(e.to);
            }
        }
        for (auto it = nodes.rbegin(); it != nodes.rend(); ++it) {
            int v = *it;
            subtree[v] = 1;
            for (const auto& e : tree[v])
                if (!removed[e.to] && parent[e.to] == v) subtree[v] += subtree[e.to];
        }
        int best = start, bestPart = int(nodes.size());
        for (int v : nodes) {
            int largest = int(nodes.size()) - subtree[v];
            for (const auto& e : tree[v])
                if (!removed[e.to] && parent[e.to] == v) largest = max(largest, subtree[e.to]);
            if (largest < bestPart) { bestPart = largest; best = v; }
        }
        return best;
    }

    void decompose(int start) {
        vector<int> nodes;
        int centre = centroid(start, nodes);
        removed[centre] = true;
        all[centre].reserve(nodes.size());
        ancestors[centre].push_back({bit[centre], centre, -1, 0});
        all[centre].emplace(bit[centre] << 2, 0);
        for (const auto& edge : tree[centre]) {
            if (removed[edge.to]) continue;
            int id = int(branch.size());
            branch.emplace_back();
            vector<Visit> visits{{edge.to, centre, edge.weight % modulus, bit[centre] ^ bit[edge.to]}};
            for (size_t i = 0; i < visits.size(); ++i) {
                Visit cur = visits[i];
                for (const auto& next : tree[cur.node]) {
                    if (removed[next.to] || next.to == cur.parent) continue;
                    visits.push_back({next.to, cur.node, (cur.distance + next.weight) % modulus, cur.mask ^ bit[next.to]});
                }
            }
            branch[id].reserve(visits.size());
            for (const auto& cur : visits) {
                ancestors[cur.node].push_back({cur.mask, centre, id, cur.distance});
                Mask key = (cur.mask << 2) | Mask(cur.distance);
                all[centre].emplace(key, 0);
                branch[id].emplace(key, 0);
            }
        }
        for (const auto& edge : tree[centre])
            if (!removed[edge.to]) decompose(edge.to);
    }

public:
    Solver(int count, int k) : n(count), modulus(k), tree(n), bit(n), removed(n), parent(n), subtree(n), ancestors(n), all(n) {
        branch.reserve(n);
    }
    void read() {
        for (Mask& x : bit) { int colour; cin >> colour; x = Mask(1) << (colour - 1); }
        colours = bit;
        sort(colours.begin(), colours.end());
        colours.erase(unique(colours.begin(), colours.end()), colours.end());
        for (int i = 1; i < n; ++i) {
            int a, b, w; cin >> a >> b >> w; --a; --b;
            tree[a].push_back({b, w}); tree[b].push_back({a, w});
        }
        decompose(0);
    }
    ll partners(int node) const {
        ll result = 0;
        for (const auto& r : ancestors[node]) {
            Mask base = r.mask ^ bit[r.centre];
            int required = (modulus - r.distance) % modulus;
            for (Mask oddColour : colours) {
                Mask key = ((base ^ oddColour) << 2) | Mask(required);
                result += all[r.centre].get(key);
                if (r.branch != -1) result -= branch[r.branch].get(key);
            }
        }
        return result;
    }
    void change(int node, int delta) {
        for (const auto& r : ancestors[node]) {
            Mask key = (r.mask << 2) | Mask(r.distance);
            all[r.centre].add(key, delta);
            if (r.branch != -1) branch[r.branch].add(key, delta);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, q;
    if (!(cin >> n >> m >> k >> q)) return 0;
    string lamps; cin >> lamps;
    Solver solver(n, k);
    solver.read();
    ll answer = 0;
    for (int v = 0; v < n; ++v) {
        if (lamps[v] == '1') {
            answer += solver.partners(v) + 1;
            solver.change(v, 1);
        }
    }
    cout << answer << '\n';
    while (q--) {
        int v; cin >> v; --v;
        if (lamps[v] == '1') {
            answer -= solver.partners(v);
            solver.change(v, -1);
            lamps[v] = '0';
        } else {
            answer += solver.partners(v) + 1;
            solver.change(v, 1);
            lamps[v] = '1';
        }
        cout << answer << '\n';
    }
}
