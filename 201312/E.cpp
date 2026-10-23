#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for (auto &s : grid)
        cin >> s;
    int start = -1, target = -1;
    vector<vector<int>> g(r * c), back(r * c);
    array<int, 4> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};
    for (int x = 0; x < r; ++x)
        for (int y = 0; y < c; ++y) {
            char ch = grid[x][y];
            int u = x * c + y;
            if (ch == 'S')
                start = u;
            if (ch == 'T')
                target = u;
            if (ch == '#')
                continue;
            for (int d = 0; d < 4; ++d) {
                bool allowed = ch == '+' || ch == 'S' || ch == 'T' || (ch == '-' && d >= 2) ||
                               (ch == '|' && d < 2) || (ch == '.' && d == 1);
                int a = x + dx[d], b = y + dy[d];
                if (allowed && a >= 0 && a < r && b >= 0 && b < c && grid[a][b] != '#') {
                    int v = a * c + b;
                    g[u].push_back(v);
                    back[v].push_back(u);
                }
            }
        }
    auto bfs = [&](int root, const vector<vector<int>> &edges) {
        vector<bool> seen(r * c);
        queue<int> q;
        q.push(root);
        seen[root] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : edges[u])
                if (!seen[v]) {
                    seen[v] = true;
                    q.push(v);
                }
        }
        return seen;
    };
    auto reachable = bfs(start, g);
    if (!reachable[target]) {
        cout << "I'm stuck!\n";
        return 0;
    }
    auto returnable = bfs(target, back);
    int answer = 0;
    for (int u = 0; u < r * c; ++u)
        answer += reachable[u] && !returnable[u];
    cout << answer << '\n';
}
