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
    for (int i = 0; i < n; i++) {
        int answer = 0;
        for (int j = 0; j < n; j++) {
            bool larger = true;
            for (int k = 0; k < m; k++)
                if (a[j][k] <= a[i][k]) {
                    larger = false;
                    break;
                }
            if (larger) {
                answer = j + 1;
                break;
            }
        }
        cout << answer << '\n';
    }
}
