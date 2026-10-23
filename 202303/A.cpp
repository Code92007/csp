#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n;
    long long a, b, answer = 0;
    cin >> n >> a >> b;
    while (n--) {
        long long x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        answer += max(0LL, min(a, xx) - max(0LL, x)) * max(0LL, min(b, yy) - max(0LL, y));
    }
    cout << answer << '\n';
}
