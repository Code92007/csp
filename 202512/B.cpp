#include <iostream>
#include <vector>
using namespace std;
int f(int x, int k) {
    return ((x * x + k * k) % 8) ^ k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> keys(m);
    for (int &k : keys)
        cin >> k;
    int inverse[512];
    for (int initial = 0; initial < 512; initial++) {
        int x = initial;
        for (int k : keys) {
            int a = x >> 6, b = (x >> 3) & 7, c = x & 7;
            x = (b << 6) | ((c ^ f(b, k)) << 3) | (a ^ f(c, k));
        }
        inverse[x] = initial;
    }
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (i)
            cout << ' ';
        cout << inverse[x];
    }
    cout << '\n';
}
