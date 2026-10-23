#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
bool wall(char c) {
    return c == '-' || c == '|' || c == '+';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, q;
    cin >> m >> n >> q;
    vector<string> a(n, string(m, '.'));
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 0) {
            int xx, yy;
            cin >> xx >> yy;
            bool horizontal = y == yy;
            if (x > xx)
                swap(x, xx);
            if (y > yy)
                swap(y, yy);
            for (int i = y; i <= yy; i++)
                for (int j = x; j <= xx; j++) {
                    char &c = a[i][j];
                    c = (c == '+' || (horizontal ? c == '|' : c == '-')) ? '+'
                        : horizontal                                     ? '-'
                                                                         : '|';
                }
        } else {
            char c;
            cin >> c;
            vector<vector<bool>> seen(n, vector<bool>(m));
            queue<pair<int, int>> todo;
            todo.push({x, y});
            seen[y][x] = true;
            int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
            while (!todo.empty()) {
                auto [u, v] = todo.front();
                todo.pop();
                a[v][u] = c;
                for (int k = 0; k < 4; k++) {
                    int xx = u + dx[k], yy = v + dy[k];
                    if (xx >= 0 && xx < m && yy >= 0 && yy < n && !seen[yy][xx] &&
                        !wall(a[yy][xx])) {
                        seen[yy][xx] = true;
                        todo.push({xx, yy});
                    }
                }
            }
        }
    }
    for (int y = n - 1; y >= 0; y--)
        cout << a[y] << '\n';
}
