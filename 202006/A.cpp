#include <iostream>
#include <vector>
using namespace std;
struct Point {
    long long x, y;
    char type;
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<Point> points(n);
    for (auto &p : points)
        cin >> p.x >> p.y >> p.type;
    while (m--) {
        long long a, b, c;
        cin >> a >> b >> c;
        int reference = 0;
        bool ok = true;
        for (auto p : points) {
            long long value = a + b * p.x + c * p.y;
            int side = value > 0 ? 1 : -1;
            if (p.type == 'B')
                side = -side;
            if (value == 0 || (reference && reference != side))
                ok = false;
            reference = side;
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
}
