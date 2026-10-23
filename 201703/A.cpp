#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int current = 0, answer = 0;
    while (n--) {
        int x;
        cin >> x;
        current += x;
        if (current >= k) {
            ++answer;
            current = 0;
        }
    }
    if (current > 0)
        ++answer;
    cout << answer << '\n';
}
