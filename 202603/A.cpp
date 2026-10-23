#include <iostream>
using namespace std;
int main() {
    int n, answer = 0;
    cin >> n;
    while (n--) {
        int x, ones = 0, bits = 0;
        cin >> x;
        while (x) {
            ones += x & 1;
            ++bits;
            x >>= 1;
        }
        answer += 2 * ones == bits;
    }
    cout << answer << '\n';
}
