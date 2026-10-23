#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        int l = max(0, i - 1), r = min(n - 1, i + 1), sum = 0;
        for (int j = l; j <= r; j++)
            sum += a[j];
        if (i)
            cout << ' ';
        cout << sum / (r - l + 1);
    }
    cout << '\n';
}
