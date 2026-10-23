#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> diff(10002);
    int previous = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x > previous) {
            ++diff[previous + 1];
            --diff[x + 1];
        }
        previous = x;
    }
    int current = 0, answer = 0;
    for (int p = 1; p <= 10000; p++) {
        current += diff[p];
        answer = max(answer, current);
    }
    cout << answer << '\n';
}
