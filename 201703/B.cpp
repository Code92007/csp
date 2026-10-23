#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    while (m--) {
        int p, q;
        cin >> p >> q;
        int index = find(a.begin(), a.end(), p) - a.begin();
        a.erase(a.begin() + index);
        a.insert(a.begin() + index + q, p);
    }
    for (int i = 0; i < n; i++) {
        if (i)
            cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}
