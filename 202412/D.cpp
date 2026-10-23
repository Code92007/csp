#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
struct Successor {
    vector<int> parent;
    explicit Successor(int n) : parent(n + 2) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        int root = x;
        while (parent[root] != root)
            root = parent[root];
        while (x != root) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1), k(n + 1), distance(n + 1, -1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> k[i];
    Successor next(n);
    vector<int> queue{1};
    distance[1] = 0;
    for (size_t head = 0; head < queue.size(); ++head) {
        int u = queue[head], right = int(min<long long>(n, 1LL * u + k[u]));
        for (int landing = next.find(u + 1); landing <= right; landing = next.find(landing)) {
            int v = landing - a[landing];
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                queue.push_back(v);
            }
            next.parent[landing] = next.find(landing + 1);
        }
    }
    cout << distance[n] << '\n';
}
