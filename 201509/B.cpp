#include <iostream>
using namespace std;
int main() {
    int y, d;
    cin >> y >> d;
    int length[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        length[2] = 29;
    int month = 1;
    while (d > length[month]) {
        d -= length[month];
        ++month;
    }
    cout << month << '\n' << d << '\n';
}
