#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int width, m, n;
    cin >> width >> m >> n;
    vector<pair<int, int>> cells(m);
    for (auto &[x, water] : cells)
        cin >> x >> water;
    sort(cells.begin(), cells.end());
    vector<int> left(m), right(m);
    for (int i = 0; i < m; ++i) {
        left[i] = i - 1;
        right[i] = i + 1;
    }
    priority_queue<int, vector<int>, greater<int>> ready;
    auto add = [&](int u) {
        if (u >= 0 && u < m && ++cells[u].second == 5)
            ready.push(u);
    };
    int alive = m;
    while (n--) {
        int position;
        cin >> position;
        int u =
            lower_bound(cells.begin(), cells.end(), pair<int, int>{position, -1}) - cells.begin();
        add(u);
        while (!ready.empty()) {
            int x = ready.top();
            ready.pop();
            int l = left[x], r = right[x];
            if (l >= 0)
                right[l] = r;
            if (r < m)
                left[r] = l;
            cells[x].second = 0;
            --alive;
            add(l);
            add(r);
        }
        cout << alive << '\n';
    }
}
