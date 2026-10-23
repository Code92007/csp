#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
struct Entry {
    int address;
    bool dirty;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ways, groups, q;
    cin >> ways >> groups >> q;
    vector<list<Entry>> cache(groups);
    unordered_map<int, list<Entry>::iterator> location;
    location.reserve(min(q, ways * groups) * 2 + 1);
    while (q--) {
        int op, address;
        cin >> op >> address;
        auto &group = cache[(address / ways) % groups];
        auto it = location.find(address);
        if (it != location.end()) {
            it->second->dirty |= op == 1;
            group.splice(group.begin(), group, it->second);
            continue;
        }
        if (int(group.size()) == ways) {
            Entry victim = group.back();
            if (victim.dirty)
                cout << "1 " << victim.address << '\n';
            location.erase(victim.address);
            group.pop_back();
        }
        cout << "0 " << address << '\n';
        group.push_front({address, op == 1});
        location[address] = group.begin();
    }
}
