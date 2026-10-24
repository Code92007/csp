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
    vector<long double> scale(n + 1, 1);
    vector<long double> angle(n + 1);
    long double angleSum = 0, compensation = 0;
    const long double turn = 2 * acosl(-1.0L);
    for (int i = 1; i <= n; i++) {
        int type;
        long double value;
        cin >> type >> value;
        scale[i] = scale[i - 1];
        if (type == 1)
            scale[i] *= value;
        else {
            long double corrected = value - compensation;
            long double next = angleSum + corrected;
            compensation = (next - angleSum) - corrected;
            angleSum = next;
        }
        angle[i] = angleSum;
    }
    cout << fixed << setprecision(10);
    while (m--) {
        int i, j;
        long double x, y;
        cin >> i >> j >> x >> y;
        long double s = scale[j] / scale[i - 1];
        long double a = fmodl(angle[j] - angle[i - 1], turn);
        cout << s * (x * cosl(a) - y * sinl(a)) << ' ' << s * (x * sinl(a) + y * cosl(a)) << '\n';
    }
}
