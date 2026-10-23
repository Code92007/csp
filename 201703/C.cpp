#include <iostream>
#include <string>
#include <vector>
using namespace std;
string inlineHTML(const string &s) {
    string out;
    bool em = false;
    for (size_t i = 0; i < s.size();) {
        if (s[i] == '_') {
            out += em ? "</em>" : "<em>";
            em = !em;
            ++i;
        } else if (s[i] == '[') {
            size_t end = s.find(']', i), close = s.find(')', end + 2);
            out += "<a href=\"" + s.substr(end + 2, close - end - 2) + "\">" +
                   inlineHTML(s.substr(i + 1, end - i - 1)) + "</a>";
            i = close + 1;
        } else
            out += s[i++];
    }
    return out;
}
string skipPrefix(const string &s, size_t p) {
    while (p < s.size() && s[p] == ' ')
        ++p;
    return s.substr(p);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> block;
    auto render = [&]() {
        if (block.empty())
            return;
        if (block[0][0] == '#') {
            size_t k = block[0].find_first_not_of('#');
            string tag = "h" + to_string(k);
            cout << '<' << tag << '>' << inlineHTML(skipPrefix(block[0], k)) << "</" << tag
                 << ">\n";
        } else if (block[0][0] == '*') {
            cout << "<ul>\n";
            for (auto &s : block)
                cout << "<li>" << inlineHTML(skipPrefix(s, 1)) << "</li>\n";
            cout << "</ul>\n";
        } else {
            cout << "<p>";
            for (size_t i = 0; i < block.size(); i++) {
                if (i)
                    cout << '\n';
                cout << inlineHTML(block[i]);
            }
            cout << "</p>\n";
        }
        block.clear();
    };
    string s;
    while (getline(cin, s)) {
        if (s.empty())
            render();
        else
            block.push_back(s);
    }
    render();
}
