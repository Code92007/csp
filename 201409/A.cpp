#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<int> a;
    while (n--) {
        int x;
        cin >> x;
        a.insert(x);
    }
    int answer = 0;
    for (int x : a)
        answer += a.count(x + 1);
    cout << answer << '\n';
}
