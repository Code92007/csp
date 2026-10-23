#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct Role {
    unordered_set<string> verbs, types, names;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<Role> roles(n);
    unordered_map<string, int> rid;
    for (int i = 0; i < n; i++) {
        string name, s;
        cin >> name;
        rid[name] = i;
        for (auto *set : {&roles[i].verbs, &roles[i].types, &roles[i].names}) {
            int k;
            cin >> k;
            while (k--) {
                cin >> s;
                set->insert(s);
            }
        }
    }
    unordered_map<string, bitset<500>> users, groups;
    while (m--) {
        string r, t, name;
        int k;
        cin >> r >> k;
        while (k--) {
            cin >> t >> name;
            (t == "u" ? users : groups)[name].set(rid[r]);
        }
    }
    while (q--) {
        string user, g, verb, type, name;
        int k;
        cin >> user >> k;
        bitset<500> allowed;
        auto u = users.find(user);
        if (u != users.end())
            allowed = u->second;
        while (k--) {
            cin >> g;
            auto it = groups.find(g);
            if (it != groups.end())
                allowed |= it->second;
        }
        cin >> verb >> type >> name;
        bool ok = false;
        for (int i = 0; i < n; i++)
            if (allowed[i]) {
                auto &r = roles[i];
                if ((r.verbs.count("*") || r.verbs.count(verb)) &&
                    (r.types.count("*") || r.types.count(type)) &&
                    (r.names.empty() || r.names.count(name))) {
                    ok = true;
                    break;
                }
            }
        cout << ok << '\n';
    }
}
