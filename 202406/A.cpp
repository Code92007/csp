#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int k = 0; k < n * m; k++) {
        int x;
        cin >> x;
        if (k % q)
            cout << ' ';
        cout << x;
        if (k % q == q - 1)
            cout << '\n';
    }
}
