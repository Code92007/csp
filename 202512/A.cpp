#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), hash(m);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> sets(m);
    for (int i = 0; i < m; i++) {
        int size;
        cin >> size;
        sets[i].resize(size);
        for (int &x : sets[i]) {
            cin >> x;
            hash[i] ^= a[x];
        }
    }
    for (int i = 0; i < m; i++) {
        int size, value = 0;
        cin >> size;
        vector<int> other(size);
        for (int &x : other) {
            cin >> x;
            value ^= a[x];
        }
        bool actual = sets[i] == other, predicted = hash[i] == value;
        cout << (actual == predicted ? "correct" : "wrong") << '\n';
    }
}
