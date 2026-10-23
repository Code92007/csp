#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
constexpr int V = 303;
int n;
vector<int> b;
vector<int8_t> memo;
bool possible(int i, int x, int y) {
    if (x < 1 || x >= V || y < 1 || y >= V)
        return false;
    int8_t &answer = memo[(i * V + x) * V + y];
    if (answer != -1)
        return answer;
    if (i == n - 1)
        return answer = (x + y) / 2 == b[i];
    for (int z = 3 * b[i] - x - y; z <= 3 * b[i] + 2 - x - y; ++z)
        if (possible(i + 1, y, z))
            return answer = 1;
    return answer = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    b.resize(n);
    for (auto &x : b)
        cin >> x;
    memo.assign(n * V * V, -1);
    vector<int> a;
    for (int x = 1; x <= 2 * b[0] && a.empty(); ++x)
        for (int y = max(1, 2 * b[0] - x); y <= 2 * b[0] + 1 - x; ++y)
            if (possible(1, x, y)) {
                a = {x, y};
                break;
            }
    for (int i = 1; i < n - 1; ++i)
        for (int z = 3 * b[i] - a[i - 1] - a[i]; z <= 3 * b[i] + 2 - a[i - 1] - a[i]; ++z)
            if (possible(i + 1, a[i], z)) {
                a.push_back(z);
                break;
            }
    for (int i = 0; i < n; ++i)
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
}
