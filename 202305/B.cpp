#include <iostream>
#include <vector>
using namespace std;
using Matrix = vector<vector<long long>>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    Matrix q(n, vector<long long>(d)), k = q, v = q;
    for (auto *a : {&q, &k, &v})
        for (auto &r : *a)
            for (auto &x : r)
                cin >> x;
    vector<long long> w(n);
    for (auto &x : w)
        cin >> x;
    Matrix small(d, vector<long long>(d));
    for (int i = 0; i < n; i++)
        for (int a = 0; a < d; a++)
            for (int b = 0; b < d; b++)
                small[a][b] += k[i][a] * v[i][b];
    for (int i = 0; i < n; i++) {
        for (int b = 0; b < d; b++) {
            long long sum = 0;
            for (int a = 0; a < d; a++)
                sum += q[i][a] * small[a][b];
            if (b)
                cout << ' ';
            cout << sum * w[i];
        }
        cout << '\n';
    }
}
