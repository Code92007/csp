#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<int, int> count;
    while (n--) {
        int x;
        cin >> x;
        ++count[x];
    }
    vector<pair<int, int>> order;
    for (auto [x, c] : count)
        order.push_back({-c, x});
    sort(order.begin(), order.end());
    for (auto [c, x] : order)
        cout << x << ' ' << -c << '\n';
}
