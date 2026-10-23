#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long double> scale(n + 1, 1), angle(n + 1);
    for (int i = 1; i <= n; i++) {
        int type;
        long double value;
        cin >> type >> value;
        scale[i] = scale[i - 1];
        angle[i] = angle[i - 1];
        if (type == 1)
            scale[i] *= value;
        else
            angle[i] += value;
    }
    cout << fixed << setprecision(8);
    while (m--) {
        int i, j;
        long double x, y;
        cin >> i >> j >> x >> y;
        long double s = scale[j] / scale[i - 1], a = angle[j] - angle[i - 1];
        cout << s * (x * cosl(a) - y * sinl(a)) << ' ' << s * (x * sinl(a) + y * cosl(a)) << '\n';
    }
}
