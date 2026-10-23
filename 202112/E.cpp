#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
struct Item {
    int id, low, high;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<vector<int>> g(n + 1);
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> bit(n + 1), parent(n + 1), size(n + 1);
    vector<bool> removed(n + 1);
    auto add = [&](int x, int d) {
        for (; x <= n; x += x & -x)
            bit[x] += d;
    };
    auto countPairs = [&](const vector<Item> &items) {
        vector<Item> a, b;
        for (auto x : items) {
            if (x.low >= x.id - k1)
                a.push_back(x);
            if (x.high <= x.id + k2)
                b.push_back(x);
        }
        sort(a.begin(), a.end(), [](Item x, Item y) { return x.high < y.high; });
        sort(b.begin(), b.end(), [](Item x, Item y) { return x.id < y.id; });
        long long answer = 0;
        size_t p = 0;
        for (auto y : b) {
            while (p < a.size() && a[p].high <= y.id + k2) {
                add(a[p].id, 1);
                ++p;
            }
            int bound = min(y.id - 1, y.low + k1);
            for (int x = bound; x > 0; x -= x & -x)
                answer += bit[x];
        }
        for (size_t i = 0; i < p; ++i)
            add(a[i].id, -1);
        return answer;
    };
    long long answer = n;
    vector<int> components{1};
    while (!components.empty()) {
        int start = components.back();
        components.pop_back();
        vector<int> order{start};
        parent[start] = 0;
        for (size_t i = 0; i < order.size(); ++i) {
            int u = order[i];
            for (int v : g[u])
                if (!removed[v] && v != parent[u]) {
                    parent[v] = u;
                    order.push_back(v);
                }
        }
        int total = order.size(), centroid = start;
        for (auto it = order.rbegin(); it != order.rend(); ++it) {
            int u = *it;
            size[u] = 1;
            int largest = 0;
            for (int v : g[u])
                if (!removed[v] && parent[v] == u) {
                    size[u] += size[v];
                    largest = max(largest, size[v]);
                }
            largest = max(largest, total - size[u]);
            if (largest <= total / 2)
                centroid = u;
        }
        vector<Item> all{{centroid, centroid, centroid}};
        for (int neighbor : g[centroid])
            if (!removed[neighbor]) {
                vector<Item> part;
                vector<tuple<int, int, int, int>> stack{
                    {neighbor, centroid, min(neighbor, centroid), max(neighbor, centroid)}};
                while (!stack.empty()) {
                    auto [u, p, lo, hi] = stack.back();
                    stack.pop_back();
                    part.push_back({u, lo, hi});
                    for (int v : g[u])
                        if (v != p && !removed[v])
                            stack.push_back({v, u, min(lo, v), max(hi, v)});
                }
                answer -= countPairs(part);
                all.insert(all.end(), part.begin(), part.end());
            }
        answer += countPairs(all);
        removed[centroid] = true;
        for (int v : g[centroid])
            if (!removed[v])
                components.push_back(v);
    }
    cout << answer << '\n';
}
