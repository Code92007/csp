#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<bool>> erase(n, vector<bool>(m));
    for (auto &r : a)
        for (int &x : r)
            cin >> x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (j + 2 < m && a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2])
                for (int d = 0; d < 3; d++)
                    erase[i][j + d] = true;
            if (i + 2 < n && a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j])
                for (int d = 0; d < 3; d++)
                    erase[i + d][j] = true;
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j)
                cout << ' ';
            cout << (erase[i][j] ? 0 : a[i][j]);
        }
        cout << '\n';
    }
}
