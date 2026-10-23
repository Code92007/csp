#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    while (k--) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        for (char c : s) {
            int xx = x, yy = y;
            if (c == 'f')
                ++yy;
            if (c == 'b')
                --yy;
            if (c == 'l')
                --xx;
            if (c == 'r')
                ++xx;
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n) {
                x = xx;
                y = yy;
            }
        }
        cout << x << ' ' << y << '\n';
    }
}
