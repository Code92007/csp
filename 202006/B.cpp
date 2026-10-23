#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, long long>> u(a), v(b);
    for (auto &[i, x] : u)
        cin >> i >> x;
    for (auto &[i, x] : v)
        cin >> i >> x;
    int i = 0, j = 0;
    long long ans = 0;
    while (i < a && j < b) {
        if (u[i].first < v[j].first)
            ++i;
        else if (u[i].first > v[j].first)
            ++j;
        else {
            ans += u[i].second * v[j].second;
            ++i;
            ++j;
        }
    }
    cout << ans << '\n';
}
