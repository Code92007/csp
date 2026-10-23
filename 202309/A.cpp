#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    long long dx = 0, dy = 0;
    while (n--) {
        long long x, y;
        cin >> x >> y;
        dx += x;
        dy += y;
    }
    while (m--) {
        long long x, y;
        cin >> x >> y;
        cout << x + dx << ' ' << y + dy << '\n';
    }
}
