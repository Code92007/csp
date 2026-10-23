#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &r : a)
        for (int &x : r)
            cin >> x;
    bool first = true;
    for (int s = 0; s <= 2 * n - 2; s++) {
        int lo = max(0, s - n + 1), hi = min(n - 1, s);
        for (int k = lo; k <= hi; k++) {
            int i = s % 2 ? k : lo + hi - k, j = s - i;
            if (!first)
                cout << ' ';
            first = false;
            cout << a[i][j];
        }
    }
    cout << '\n';
}
