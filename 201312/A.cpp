#include <iostream>
#include <map>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<int, int> count;
    while (n--) {
        int x;
        cin >> x;
        ++count[x];
    }
    int answer = 0, most = 0;
    for (auto [x, c] : count)
        if (c > most) {
            most = c;
            answer = x;
        }
    cout << answer << '\n';
}
