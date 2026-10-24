#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long double> scale(n + 1, 1);
    vector<long long> angleMillis(n + 1);
    const long double turn = 2 * acosl(-1.0L);
    for (int i = 1; i <= n; i++) {
        int type;
        string value;
        cin >> type >> value;
        scale[i] = scale[i - 1];
        angleMillis[i] = angleMillis[i - 1];
        if (type == 1)
            scale[i] *= stold(value);
        else
            angleMillis[i] += llround(stold(value) * 1000);
    }
    cout << fixed << setprecision(10);
    while (m--) {
        int i, j;
        long double x, y;
        cin >> i >> j >> x >> y;
        long double s = scale[j] / scale[i - 1];
        long double a = fmodl((angleMillis[j] - angleMillis[i - 1]) / 1000.0L, turn);
        cout << s * (x * cosl(a) - y * sinl(a)) << ' ' << s * (x * sinl(a) + y * cosl(a)) << '\n';
    }
}
