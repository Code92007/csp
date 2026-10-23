#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> original(n + 1);
    vector<int> head(n + 1), tail(n + 1), next(n + 1), count(n + 1), depth(n + 1), tin(n + 1),
        tout(n + 1), bit(n + 2);
    auto append = [&](int u, int a, int b) {
        if (!a)
            return;
        if (tail[u])
            next[tail[u]] = a;
        else
            head[u] = a;
        tail[u] = b;
    };
    for (int i = 2, p; i <= n; ++i) {
        cin >> p;
        original[p].push_back(i);
        append(p, i, i);
        ++count[p];
    }
    vector<long long> data(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> data[i];
    int timer = 0;
    depth[1] = 1;
    vector<pair<int, bool>> stack{{1, false}};
    while (!stack.empty()) {
        auto [u, exit] = stack.back();
        stack.pop_back();
        if (exit) {
            tout[u] = timer;
            continue;
        }
        tin[u] = ++timer;
        stack.push_back({u, true});
        for (int v : original[u]) {
            depth[v] = depth[u] + 1;
            stack.push_back({v, false});
        }
    }
    auto add = [&](int x, int d) {
        for (; x <= n; x += x & -x)
            bit[x] += d;
    };
    while (m--) {
        int op, u;
        cin >> op >> u;
        if (op == 2) {
            int d = depth[u];
            for (int x = tin[u]; x; x -= x & -x)
                d += bit[x];
            cout << d << '\n';
        } else {
            // Save the old list before appending grandchildren: delete only one level.
            int v = head[u];
            head[u] = tail[u] = count[u] = 0;
            while (v) {
                int following = next[v];
                next[v] = 0;
                data[u] += data[v];
                append(u, head[v], tail[v]);
                count[u] += count[v];
                add(tin[v], -1);
                add(tout[v] + 1, 1);
                v = following;
            }
            cout << count[u] << ' ' << data[u] << '\n';
        }
    }
}
