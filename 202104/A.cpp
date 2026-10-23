#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, L;
    cin >> n >> m >> L;
    vector<int> count(L);
    for (int i = 0; i < n * m; i++) {
        int x;
        cin >> x;
        ++count[x];
    }
    for (int i = 0; i < L; i++) {
        if (i)
            cout << ' ';
        cout << count[i];
    }
    cout << '\n';
}
