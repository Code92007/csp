#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L, S;
    cin >> n >> L >> S;
    vector<pair<int, int>> trees(n);
    for (auto &[x, y] : trees)
        cin >> x >> y;
    vector<vector<int>> b(S + 1, vector<int>(S + 1));
    int ones = 0;
    for (int x = S; x >= 0; x--)
        for (int y = 0; y <= S; y++) {
            cin >> b[x][y];
            ones += b[x][y];
        }
    int answer = 0;
    for (auto [x, y] : trees) {
        if (x + S > L || y + S > L)
            continue;
        int count = 0;
        bool ok = true;
        for (auto [u, v] : trees) {
            int dx = u - x, dy = v - y;
            if (dx >= 0 && dx <= S && dy >= 0 && dy <= S) {
                ++count;
                if (!b[dx][dy]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok && count == ones)
            ++answer;
    }
    cout << answer << '\n';
}
