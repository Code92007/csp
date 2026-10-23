#include <iostream>
using namespace std;
bool skip(int x) {
    if (x % 7 == 0)
        return true;
    while (x) {
        if (x % 10 == 7)
            return true;
        x /= 10;
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    int count[4] = {}, spoken = 0;
    for (int x = 1; spoken < n; x++) {
        if (skip(x))
            ++count[(x - 1) % 4];
        else
            ++spoken;
    }
    for (int x : count)
        cout << x << '\n';
}
