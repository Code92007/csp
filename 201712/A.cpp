#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    long long answer = numeric_limits<long long>::max();
    for (int i = 1; i < n; i++)
        answer = min(answer, a[i] - a[i - 1]);
    cout << answer << '\n';
}
