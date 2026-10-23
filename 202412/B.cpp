#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> a(n + 1), b(n + 1), need(n + 1), pre(n + 1), suf(n + 2, -(1LL << 60));
    for (auto &x : a)
        cin >> x;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    long long cost = 0;
    for (int i = 0; i <= n; i++) {
        cost += a[i] - b[i];
        need[i] = cost;
        pre[i] = i ? max(pre[i - 1], need[i]) : need[i];
    }
    for (int i = n; i >= 0; i--)
        suf[i] = max(suf[i + 1], need[i]);
    for (int i = 1; i <= n; i++) {
        if (i > 1)
            cout << ' ';
        cout << max(pre[i - 1], suf[i] + b[i]);
    }
    cout << '\n';
}
