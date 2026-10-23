#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> articles(m + 1), total(m + 1), last(m + 1);
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        while (l--) {
            int word;
            cin >> word;
            ++total[word];
            if (last[word] != i) {
                ++articles[word];
                last[word] = i;
            }
        }
    }
    for (int i = 1; i <= m; i++)
        cout << articles[i] << ' ' << total[i] << '\n';
}
