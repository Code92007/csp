#include <iostream>
using namespace std;
int main() {
    int n, previous = 0, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0 || x != previous)
            ++count;
        previous = x;
    }
    cout << count << '\n';
}
