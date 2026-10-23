#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &r : a)
        for (int &x : r)
            cin >> x;
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (i)
                cout << ' ';
            cout << a[i][j];
        }
        cout << '\n';
    }
}
