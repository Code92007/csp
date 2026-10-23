#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int board[15][10];
    for (auto &r : board)
        for (int &x : r)
            cin >> x;
    vector<pair<int, int>> shape;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            if (x)
                shape.push_back({i, j});
        }
    int col;
    cin >> col;
    --col;
    auto fits = [&](int top) {
        for (auto [r, c] : shape)
            if (top + r >= 15 || board[top + r][col + c])
                return false;
        return true;
    };
    int top = 0;
    while (fits(top + 1))
        ++top;
    for (auto [r, c] : shape)
        board[top + r][col + c] = 1;
    for (auto &r : board) {
        for (int j = 0; j < 10; j++) {
            if (j)
                cout << ' ';
            cout << r[j];
        }
        cout << '\n';
    }
}
