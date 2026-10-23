#include <iostream>
#include <string>
using namespace std;
string trim(const string &s) {
    size_t l = s.find_first_not_of(' ');
    if (l == string::npos)
        return "";
    return s.substr(l, s.find_last_not_of(' ') - l + 1);
}
long long lines(const string &s, int width) {
    if (s.empty())
        return 1;
    long long ans = 0;
    size_t p = 0;
    while (p < s.size()) {
        ++ans;
        p += width;
        while (p < s.size() && s[p] == ' ')
            ++p;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w;
    cin >> w;
    string s, text;
    getline(cin, s);
    int state = 0;
    long long answer = 0;
    bool hadBlock = false;
    auto flush = [&]() {
        if (state)
            answer += lines(text, state == 2 ? w - 3 : w);
        text.clear();
    };
    auto begin = [&](int kind) {
        if (hadBlock)
            ++answer;
        hadBlock = true;
        state = kind;
    };
    auto append = [&](const string &part) {
        string t = trim(part);
        if (t.empty())
            return;
        if (!text.empty())
            text += ' ';
        text += t;
    };
    while (getline(cin, s)) {
        bool blank = trim(s).empty();
        bool bullet = s.size() >= 2 && s[0] == '*' && s[1] == ' ';
        bool indent = s.size() >= 2 && s[0] == ' ' && s[1] == ' ';
        if (blank) {
            flush();
            state = 0;
            continue;
        }
        if (bullet) {
            if (state == 2)
                flush();
            else {
                flush();
                begin(2);
            }
            append(s.substr(2));
        } else if (state == 2 && indent) {
            append(s.substr(2));
        } else {
            if (state != 1) {
                flush();
                begin(1);
            }
            append(s);
        }
    }
    flush();
    cout << answer << '\n';
}
