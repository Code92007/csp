#include <iostream>
using namespace std;
int main() {
    long long b, c, l, r, answer = 0;
    cin >> b >> c >> l >> r;
    if (l % 2)
        ++l;
    for (long long x = l; x <= r; x += 2)
        answer += 2 * (x * x + b * x + c);
    cout << answer << '\n';
}
