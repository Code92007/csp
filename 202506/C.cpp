#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using u64 = uint64_t;
int digit(char c) {
    if (c == ' ')
        return 0;
    if (c >= '0' && c <= '9')
        return c - '0' + 1;
    if (c == '_')
        return 37;
    return c - 'A' + 11;
}
char symbol(int x) {
    if (x == 0)
        return ' ';
    if (x <= 10)
        return char('0' + x - 1);
    if (x == 37)
        return '_';
    return char('A' + x - 11);
}
u64 numeric(string s) {
    s.resize(11, ' ');
    u64 value = 0;
    for (char c : s)
        value = value * 38 + digit(c);
    return value;
}
string full(u64 x) {
    string s(11, ' ');
    for (int i = 10; i >= 0; --i) {
        s[i] = symbol(x % 38);
        x /= 38;
    }
    while (!s.empty() && s.back() == ' ')
        s.pop_back();
    return s;
}
string typical(u64 x) {
    string s(6, ' ');
    for (int i = 5; i >= 3; --i) {
        s[i] = char('A' + x % 26);
        x /= 26;
    }
    s[2] = char('0' + x % 10);
    x /= 10;
    int second = x % 36;
    x /= 36;
    s[1] = second < 10 ? char('0' + second) : char('A' + second - 10);
    s[0] = symbol(x);
    if (s[0] == ' ')
        s.erase(s.begin());
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<u64, string> known25;
    vector<string> known12(4096);
    auto remember = [&](const string &name) {
        u64 hash = numeric(name) * u64(47055833459ULL);
        known25[hash >> 39] = name;
        known12[hash >> 52] = name;
    };
    while (n--) {
        string bits;
        cin >> bits;
        auto value = [&](int begin, int length) {
            u64 x = 0;
            for (int i = 0; i < length; ++i)
                x = x * 2 + (bits[begin + i] - '0');
            return x;
        };
        string receiver, sender;
        bool direct_receiver = false, direct_sender = false;
        int location = 0;
        if (bits[0] == '0') {
            auto decode = [&](u64 x, bool &direct) {
                direct = x >= (1ULL << 25);
                if (direct)
                    return typical(x - (1ULL << 25));
                auto it = known25.find(x);
                return it == known25.end() ? string("###") : "#" + it->second;
            };
            receiver = decode(value(1, 28), direct_receiver);
            sender = decode(value(29, 28), direct_sender);
            location = value(57, 15);
        } else {
            string literal = full(value(1, 58));
            const string &prior = known12[value(59, 12)];
            string inferred = prior.empty() ? "###" : "#" + prior;
            if (bits[71] == '0') {
                receiver = inferred;
                sender = literal;
                direct_sender = true;
            } else {
                receiver = literal;
                sender = inferred;
                direct_receiver = true;
            }
        }
        cout << receiver << ' ' << sender;
        if (location)
            cout << ' ' << location;
        cout << '\n';
        if (direct_receiver)
            remember(receiver);
        if (direct_sender)
            remember(sender);
    }
}
