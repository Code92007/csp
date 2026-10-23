#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    long long m;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(n);
    int hi = k;
    for (auto &[t, c] : a) {
        cin >> t >> c;
        hi = max(hi, t);
    }
    int lo = k;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        long long need = 0;
        for (auto [t, c] : a)
            if (t > mid)
                need += 1LL * (t - mid) * c;
        if (need <= m)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << '\n';
}
