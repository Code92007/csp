#include <algorithm>
#include <bitset>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using Bits = bitset<2500>;
unordered_map<int, vector<pair<int, int>>> attrs;
string expr;
size_t posi;
int number() {
    int x = 0;
    while (posi < expr.size() && isdigit(expr[posi]))
        x = x * 10 + expr[posi++] - '0';
    return x;
}
Bits parse() {
    if (expr[posi] == '&' || expr[posi] == '|') {
        char op = expr[posi++];
        ++posi;
        Bits a = parse();
        posi += 2;
        Bits b = parse();
        ++posi;
        return op == '&' ? (a & b) : (a | b);
    }
    int key = number();
    char op = expr[posi++];
    int value = number();
    Bits ans;
    auto it = attrs.find(key);
    if (it == attrs.end())
        return ans;
    const auto &v = it->second;
    if (op == ':') {
        auto l = lower_bound(v.begin(), v.end(), pair<int, int>{value, -1});
        for (; l != v.end() && l->first == value; ++l)
            ans.set(l->second);
    } else
        for (auto [val, id] : v)
            if (val != value)
                ans.set(id);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> dn;
    for (int i = 0; i < n; i++) {
        int d, k;
        cin >> d >> k;
        dn.push_back({d, i});
        while (k--) {
            int a, v;
            cin >> a >> v;
            attrs[a].push_back({v, i});
        }
    }
    for (auto &[key, v] : attrs)
        sort(v.begin(), v.end());
    sort(dn.begin(), dn.end());
    int m;
    cin >> m;
    while (m--) {
        cin >> expr;
        posi = 0;
        Bits ans = parse();
        bool first = true;
        for (auto [d, i] : dn)
            if (ans[i]) {
                if (!first)
                    cout << ' ';
                cout << d;
                first = false;
            }
        cout << '\n';
    }
}
