#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        bool letter = false, digit = false, special = false, repeat = false;
        int count[128] = {};
        for (unsigned char c : s) {
            if (isalpha(c))
                letter = true;
            else if (isdigit(c))
                digit = true;
            else
                special = true;
            if (++count[c] > 2)
                repeat = true;
        }
        cout << (!(letter && digit && special) ? 0 : repeat ? 1 : 2) << '\n';
    }
}
