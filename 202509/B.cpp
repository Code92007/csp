#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L;
    cin >> n >> L;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &r : a)
        for (int &x : r)
            cin >> x;
    string pattern[] = {"111111111", "100100101", "100111110", "100001100", "111111100"};
    vector<int> diff(L + 1);
    for (int i = 0; i + 4 < n; i++)
        for (int j = 0; j + 8 < n; j++) {
            int low = 0, high = L - 1;
            for (int u = 0; u < 5; u++)
                for (int v = 0; v < 9; v++) {
                    if (pattern[u][v] == '1')
                        high = min(high, a[i + u][j + v]);
                    else
                        low = max(low, a[i + u][j + v] + 1);
                }
            if (low <= high) {
                ++diff[low];
                --diff[high + 1];
            }
        }
    int sum = 0;
    for (int k = 0; k < L; k++) {
        sum += diff[k];
        if (sum)
            cout << k << '\n';
    }
}
