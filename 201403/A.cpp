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
        if (x > 0 && a.count(-x))
            ++answer;
    cout << answer << '\n';
}
