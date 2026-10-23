#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long previous = 0, low = 0, high = 0;
    while (n--) {
        long long b;
        cin >> b;
        high += b;
        if (b > previous)
            low += b;
        previous = b;
    }
    cout << high << '\n' << low << '\n';
}
