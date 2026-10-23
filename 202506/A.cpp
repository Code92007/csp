#include <iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    while (k--) {
        int mu, sigma, n;
        cin >> mu >> sigma >> n;
        int value = 100 * (n - mu) / sigma;
        cout << value / 10 + 1 << ' ' << value % 10 + 1 << '\n';
    }
}
