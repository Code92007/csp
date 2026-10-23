#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    bool paint[100][100] = {};
    while (n--) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        for (int i = x; i < xx; i++)
            for (int j = y; j < yy; j++)
                paint[i][j] = true;
    }
    int answer = 0;
    for (auto &r : paint)
        for (bool v : r)
            answer += v;
    cout << answer << '\n';
}
