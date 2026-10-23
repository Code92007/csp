#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int z;
    cin >> z;
    vector<string> image(z);
    for (auto &row : image)
        cin >> row;
    int key_length, t;
    cin >> key_length >> t;
    vector<array<int, 6>> ops(t);
    for (auto &op : ops)
        for (auto &x : op)
            cin >> x;
    int orientation = 0;
    auto at = [&](int r, int c) -> char & {
        for (int i = 0; i < orientation; ++i) {
            int next = c;
            c = z - 1 - r;
            r = next;
        }
        return image[r][c];
    };
    for (auto it = ops.rbegin(); it != ops.rend(); ++it) {
        auto op = *it;
        if (op[0] == 1) {
            int u = op[1] - 1, v = op[2] - 1, length = op[3], turns = op[4] / 90;
            orientation = (orientation + 4 - op[5]) % 4;
            vector<string> copy(length, string(length, ' '));
            for (int i = 0; i < length; ++i)
                for (int j = 0; j < length; ++j)
                    copy[i][j] = at(u + i, v + j);
            for (int i = 0; i < length; ++i)
                for (int j = 0; j < length; ++j) {
                    int r = i, c = j;
                    for (int k = 0; k < turns; ++k) {
                        int next = c;
                        c = length - 1 - r;
                        r = next;
                    }
                    at(u + i, v + j) = copy[r][c];
                }
        } else {
            int u = op[1] - 1, d = op[2] - 1, l = op[3] - 1, r = op[4] - 1;
            vector<string> copy(d - u + 1, string(r - l + 1, ' '));
            for (int i = u; i <= d; ++i)
                for (int j = l; j <= r; ++j)
                    copy[i - u][j - l] = at(i, j);
            for (int i = u; i <= d; ++i)
                for (int j = l; j <= r; ++j)
                    at(i, j) = op[5] == 1 ? copy[d - i][j - l] : copy[i - u][r - j];
        }
    }
    int n = 0, m = 0;
    while (n < z && at(n, 0) != '?')
        ++n;
    while (m < z && at(0, m) != '?')
        ++m;
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << at(i, j);
        cout << '\n';
    }
}
