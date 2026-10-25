#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct AngleSum {
    long double high = 0, low = 0;
    void add(long double value) {
        long double next = high + value;
        // Retain the rounding error instead of rounding the compensated total
        // back to a single floating-point value at every prefix.
        low += fabsl(high) >= fabsl(value) ? (high - next) + value : (value - next) + high;
        high = next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long double> scale(n + 1, 1);
    vector<AngleSum> angle(n + 1);
    for (int i = 1; i <= n; ++i) {
        int type;
        long double value;
        cin >> type >> value;
        scale[i] = scale[i - 1];
        angle[i] = angle[i - 1];
        if (type == 1)
            scale[i] *= value;
        else
            angle[i].add(value);
    }
    cout << fixed << setprecision(10);
    while (m--) {
        int i, j;
        long double x, y;
        cin >> i >> j >> x >> y;
        long double a = angle[j].high, b = angle[i - 1].high;
        long double difference = a - b;
        long double virtualB = a - difference;
        long double residual = (a - (difference + virtualB)) + (virtualB - b);
        residual += angle[j].low - angle[i - 1].low;
        // Evaluate the high/low parts separately. Do not reduce a large angle
        // with a rounded 2*pi constant, or add the small residual back too early.
        long double c = cosl(difference), s = sinl(difference);
        long double dc = cosl(residual), ds = sinl(residual);
        long double cosine = c * dc - s * ds, sine = s * dc + c * ds;
        long double factor = scale[j] / scale[i - 1];
        cout << factor * (x * cosine - y * sine) << ' '
             << factor * (x * sine + y * cosine) << '\n';
    }
}
