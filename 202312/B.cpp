#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        long long n, answer = 1;
        int k;
        cin >> n >> k;
        for (long long p = 2; p <= n / p; p++) {
            int count = 0;
            long long power = 1;
            while (n % p == 0) {
                n /= p;
                power *= p;
                ++count;
            }
            if (count >= k)
                answer *= power;
        }
        if (n > 1 && k <= 1)
            answer *= n;
        cout << answer << '\n';
    }
}
