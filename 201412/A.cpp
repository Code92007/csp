#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> count(n + 1);
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        if (i)
            cout << ' ';
        cout << ++count[id];
    }
    cout << '\n';
}
