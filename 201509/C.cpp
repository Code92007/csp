#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    string line;
    getline(cin, line);
    vector<string> lines(m);
    for (auto &s : lines)
        getline(cin, s);
    unordered_map<string, string> values;
    while (n--) {
        getline(cin, line);
        size_t space = line.find(' '), quote = line.find('"', space);
        values[line.substr(0, space)] = line.substr(quote + 1, line.size() - quote - 2);
    }
    for (auto &s : lines) {
        for (size_t p = 0; p < s.size();) {
            size_t l = s.find("{{ ", p);
            if (l == string::npos) {
                cout << s.substr(p);
                break;
            }
            cout << s.substr(p, l - p);
            size_t r = s.find(" }}", l + 3);
            auto it = values.find(s.substr(l + 3, r - l - 3));
            if (it != values.end())
                cout << it->second;
            p = r + 3;
        }
        cout << '\n';
    }
}
