#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string format, line;
    int n;
    cin >> format >> n;
    int kind[26] = {};
    for (size_t i = 0; i < format.size(); i++)
        if (format[i] != ':')
            kind[format[i] - 'a'] = i + 1 < format.size() && format[i + 1] == ':' ? 2 : 1;
    getline(cin, line);
    for (int test = 1; test <= n; test++) {
        getline(cin, line);
        istringstream in(line);
        string word;
        in >> word;
        map<char, string> found;
        while (in >> word) {
            if (word.size() != 2 || word[0] != '-' || word[1] < 'a' || word[1] > 'z' ||
                !kind[word[1] - 'a'])
                break;
            char c = word[1];
            string value;
            if (kind[c - 'a'] == 2 && !(in >> value))
                break;
            found[c] = value;
        }
        cout << "Case " << test << ':';
        for (auto [c, value] : found) {
            cout << " -" << c;
            if (kind[c - 'a'] == 2)
                cout << ' ' << value;
        }
        cout << '\n';
    }
}
