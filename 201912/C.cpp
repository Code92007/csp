#include <cctype>
#include <iostream>
#include <map>
#include <string>
using namespace std;
using Counts = map<string, long long>;
string s;
size_t p;
long long number() {
    if (p == s.size() || !isdigit(s[p]))
        return 1;
    long long n = 0;
    while (p < s.size() && isdigit(s[p]))
        n = n * 10 + s[p++] - '0';
    return n;
}
void add(Counts &a, const Counts &b, long long factor) {
    for (auto &[element, count] : b)
        a[element] += count * factor;
}
Counts formula() {
    Counts result;
    while (p < s.size() && s[p] != ')' && s[p] != '+' && s[p] != '=') {
        Counts term;
        if (s[p] == '(') {
            ++p;
            term = formula();
            ++p;
        } else {
            string element(1, s[p++]);
            if (p < s.size() && islower(s[p]))
                element += s[p++];
            term[element] = 1;
        }
        long long factor = number();
        add(result, term, factor);
    }
    return result;
}
Counts expression() {
    Counts result;
    while (p < s.size() && s[p] != '=') {
        long long factor = number();
        Counts term = formula();
        add(result, term, factor);
        if (p < s.size() && s[p] == '+')
            ++p;
        else
            break;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        p = 0;
        Counts a = expression();
        ++p;
        Counts b = expression();
        cout << (a == b ? 'Y' : 'N') << '\n';
    }
}
