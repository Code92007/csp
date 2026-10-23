#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> ordinary(n), even(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        size_t point = s.find('.');
        int a = stoi(s.substr(0, point)), b = s[point + 1] - '0';
        ordinary[i] = a + (b >= 5);
        even[i] = a + (b > 5 || (b == 5 && a % 2 == 1));
    }
    for (int i = 0; i < n; ++i) cout << ordinary[i] << (i + 1 == n ? '\n' : ' ');
    for (int i = 0; i < n; ++i) cout << even[i] << (i + 1 == n ? '\n' : ' ');
}
