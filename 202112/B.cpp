#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long N;
    cin >> n >> N;
    vector<long long> a(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = N;
    long long r = N / (n + 1), x = 0, ans = 0;
    int f = 0;
    while (x < N) {
        while (f < n && a[f + 1] <= x)
            ++f;
        long long g = x / r, next = min(a[f + 1], (g + 1) * r);
        ans += (next - x) * llabs(g - f);
        x = next;
    }
    cout << ans << '\n';
}
