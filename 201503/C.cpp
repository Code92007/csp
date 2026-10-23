#include <iomanip>
#include <iostream>
using namespace std;
bool leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
int main() {
    int a, b, c, y1, y2;
    cin >> a >> b >> c >> y1 >> y2;
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int first = 2;
    for (int y = 1850; y <= y2; y++) {
        if (y >= y1) {
            int weekday = first;
            for (int m = 1; m < a; m++)
                weekday = (weekday + month[m] + (m == 2 && leap(y))) % 7;
            int day = 1 + (c % 7 - weekday + 7) % 7 + 7 * (b - 1);
            if (day > month[a] + (a == 2 && leap(y)))
                cout << "none\n";
            else
                cout << y << '/' << setfill('0') << setw(2) << a << '/' << setw(2) << day << '\n';
        }
        first = (first + 365 + leap(y)) % 7;
    }
}
