#include <iostream>
using namespace std;
int main() {
    int n;
    long long N, answer = 0;
    cin >> n >> N;
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        answer += N - a;
    }
    cout << answer << '\n';
}
