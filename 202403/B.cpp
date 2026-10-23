#include <cctype>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
string lower(string s) {
    for (char &c : s)
        c = tolower(static_cast<unsigned char>(c));
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    unordered_set<string> a, b;
    string s;
    while (n--) {
        cin >> s;
        a.insert(lower(s));
    }
    while (m--) {
        cin >> s;
        b.insert(lower(s));
    }
    size_t common = 0;
    for (auto &s : a)
        common += b.count(s);
    cout << common << '\n' << a.size() + b.size() - common << '\n';
}
