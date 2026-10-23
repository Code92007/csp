#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
ll norm(ll x) {
    return (x % MOD + MOD) % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string line, t;
    getline(cin, line);
    getline(cin, line);
    istringstream in(line);
    vector<string> tokens;
    while (in >> t)
        tokens.push_back(t);
    while (m--) {
        int var;
        cin >> var;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = norm(a[i]);
        }
        vector<pair<ll, ll>> st;
        for (auto &s : tokens) {
            if (s == "+" || s == "-" || s == "*") {
                auto [v, d] = st.back();
                st.pop_back();
                auto [u, c] = st.back();
                st.pop_back();
                if (s == "+")
                    st.push_back({(u + v) % MOD, (c + d) % MOD});
                else if (s == "-")
                    st.push_back({norm(u - v), norm(c - d)});
                else
                    st.push_back({u * v % MOD, (c * v + u * d) % MOD});
            } else if (s[0] == 'x') {
                int id = stoi(s.substr(1));
                st.push_back({a[id], id == var});
            } else
                st.push_back({norm(stoll(s)), 0});
        }
        cout << st.back().second << '\n';
    }
}
