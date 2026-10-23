#include <iostream>
#include <set>
#include <utility>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<pair<int, int>> a;
    while (n--) {
        int x, y;
        cin >> x >> y;
        a.insert({x, y});
    }
    int count[5] = {};
    for (auto [x, y] : a) {
        if (!a.count({x - 1, y}) || !a.count({x + 1, y}) || !a.count({x, y - 1}) ||
            !a.count({x, y + 1}))
            continue;
        int score = 0;
        for (int dx : {-1, 1})
            for (int dy : {-1, 1})
                score += a.count({x + dx, y + dy});
        ++count[score];
    }
    for (int x : count)
        cout << x << '\n';
}
