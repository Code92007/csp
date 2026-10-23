#include <cctype>
#include <iostream>
#include <string>
using namespace std;
string lower(string s) {
    for (char &c : s)
        c = tolower(static_cast<unsigned char>(c));
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string pattern, line;
    int sensitive, n;
    cin >> pattern >> sensitive >> n;
    if (!sensitive)
        pattern = lower(pattern);
    while (n--) {
        cin >> line;
        string key = sensitive ? line : lower(line);
        if (key.find(pattern) != string::npos)
            cout << line << '\n';
    }
}
