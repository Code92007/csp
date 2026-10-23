#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, line;
    getline(cin, s);
    s = s.substr(1, s.size() - 2);
    int jump[31][128];
    for (int c = 0; c < 128; c++)
        jump[0][c] = c;
    int n;
    cin >> n;
    getline(cin, line);
    while (n--) {
        getline(cin, line);
        jump[0][int(line[1])] = line[2];
    }
    for (int b = 1; b < 31; b++)
        for (int c = 0; c < 128; c++)
            jump[b][c] = jump[b - 1][jump[b - 1][c]];
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << '#';
        for (char ch : s) {
            int c = ch;
            for (int b = 0; b < 31; b++)
                if (k & (1 << b))
                    c = jump[b][c];
            cout << char(c);
        }
        cout << "#\n";
    }
}
