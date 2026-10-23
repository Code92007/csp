#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<double> p(n);
    for (auto &x : p)
        cin >> x;
    int masks = 1 << n, max_coins = n * k;
    vector<int> count(masks);
    for (int s = 1; s < masks; ++s)
        count[s] = count[s >> 1] + (s & 1);
    vector<vector<double>> expected(masks, vector<double>(max_coins + 1));
    for (int s = masks - 2; s >= 0; --s) {
        int need = (n - count[s]) * k;
        double duplicate = 0;
        for (int i = 0; i < n; ++i)
            if (s >> i & 1)
                duplicate += p[i];
        for (int coins = need - 1; coins >= 0; --coins) {
            double value = 1 + duplicate * expected[s][coins + 1];
            for (int i = 0; i < n; ++i)
                if (!(s >> i & 1))
                    value += p[i] * expected[s | (1 << i)][coins];
            expected[s][coins] = value;
        }
    }
    cout << fixed << setprecision(12) << expected[0][0] << '\n';
}
