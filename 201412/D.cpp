#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
struct Edge {
    int u, v, w;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto &e : edges)
        cin >> e.u >> e.v >> e.w;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    vector<int> parent(n + 1), size(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
    auto find = [&](int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    };
    long long answer = 0;
    for (auto e : edges) {
        int u = find(e.u), v = find(e.v);
        if (u == v)
            continue;
        if (size[u] < size[v])
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        answer += e.w;
    }
    cout << answer << '\n';
}
