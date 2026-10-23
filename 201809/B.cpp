#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (auto &[l, r] : a)
        cin >> l >> r;
    for (auto &[l, r] : b)
        cin >> l >> r;
    int i = 0, j = 0, answer = 0;
    while (i < n && j < n) {
        answer += max(0, min(a[i].second, b[j].second) - max(a[i].first, b[j].first));
        if (a[i].second < b[j].second)
            ++i;
        else
            ++j;
    }
    cout << answer << '\n';
}
