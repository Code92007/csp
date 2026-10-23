#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
vector<string> parse(const string &s, vector<string> stack = {}) {
    istringstream in(s);
    string part;
    while (getline(in, part, '/')) {
        if (part.empty() || part == ".")
            continue;
        if (part == "..") {
            if (!stack.empty())
                stack.pop_back();
        } else
            stack.push_back(part);
    }
    return stack;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string cwd, line;
    cin >> cwd;
    getline(cin, line);
    auto base = parse(cwd);
    while (n--) {
        getline(cin, line);
        auto result = parse(line, !line.empty() && line[0] == '/' ? vector<string>{} : base);
        if (result.empty())
            cout << '/';
        else
            for (auto &s : result)
                cout << '/' << s;
        cout << '\n';
    }
}
