#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int weight = 1, sum = 0;
    for (size_t i = 0; i + 1 < s.size(); i++)
        if (s[i] != '-')
            sum += (s[i] - '0') * weight++;
    int r = sum % 11;
    char correct = r == 10 ? 'X' : char('0' + r);
    if (s.back() == correct)
        cout << "Right\n";
    else {
        s.back() = correct;
        cout << s << '\n';
    }
}
