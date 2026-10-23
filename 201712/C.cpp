#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using Field = array<bool, 60>;
int value(string s, int kind) {
    for (char &c : s)
        c = tolower(static_cast<unsigned char>(c));
    if (isdigit(s[0]))
        return stoi(s);
    string names = kind == 3 ? "janfebmaraprmayjunjulaugsepoctnovdec" : "sunmontuewedthufrisat";
    return int(names.find(s) / 3) + (kind == 3);
}
Field parse(string s, int kind) {
    const int lo[] = {0, 0, 1, 1, 0}, hi[] = {59, 23, 31, 12, 6};
    Field a{};
    if (s == "*") {
        for (int i = lo[kind]; i <= hi[kind]; i++)
            a[i] = true;
        return a;
    }
    istringstream in(s);
    string part;
    while (getline(in, part, ',')) {
        size_t p = part.find('-');
        int l = value(part.substr(0, p), kind),
            r = p == string::npos ? l : value(part.substr(p + 1), kind);
        for (int i = l; i <= r; i++)
            a[i] = true;
    }
    return a;
}
struct Rule {
    array<Field, 5> fields;
    vector<int> minutes, hours;
    string command;
};
bool leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long start, finish;
    cin >> n >> start >> finish;
    vector<Rule> rules(n);
    for (auto &r : rules) {
        for (int j = 0; j < 5; j++) {
            string s;
            cin >> s;
            r.fields[j] = parse(s, j);
        }
        cin >> r.command;
        for (int i = 0; i < 60; i++)
            if (r.fields[0][i])
                r.minutes.push_back(i);
        for (int i = 0; i < 24; i++)
            if (r.fields[1][i])
                r.hours.push_back(i);
    }
    int weekday = 4;
    int lengths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int y = 1970; y <= finish / 100000000; y++)
        for (int mo = 1; mo <= 12; mo++)
            for (int d = 1; d <= lengths[mo] + (mo == 2 && leap(y));
                 d++, weekday = (weekday + 1) % 7) {
                long long date = (y * 10000 + mo * 100 + d) * 10000LL;
                if (date + 2359 < start || date >= finish)
                    continue;
                vector<pair<long long, int>> events;
                for (int i = 0; i < n; i++) {
                    auto &r = rules[i];
                    if (!r.fields[2][d] || !r.fields[3][mo] || !r.fields[4][weekday])
                        continue;
                    for (int h : r.hours)
                        for (int m : r.minutes) {
                            long long t = date + h * 100 + m;
                            if (start <= t && t < finish)
                                events.push_back({t, i});
                        }
                }
                sort(events.begin(), events.end());
                for (auto [t, i] : events)
                    cout << t << ' ' << rules[i].command << '\n';
            }
}
