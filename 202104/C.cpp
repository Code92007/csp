#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
struct IP {
    int state = 0;
    string owner;
    ll expiry = 0;
    int version = 0;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    ll def, hi, lo;
    string host;
    cin >> n >> def >> hi >> lo >> host >> q;
    vector<IP> ip(n + 1);
    set<int> free, expired;
    for (int i = 1; i <= n; i++)
        free.insert(i);
    unordered_map<string, int> owned;
    using Event = tuple<ll, int, int>;
    priority_queue<Event, vector<Event>, greater<Event>> events;
    auto clear = [&](int x) {
        owned.erase(ip[x].owner);
        ip[x].owner.clear();
        ip[x].state = 0;
        ip[x].expiry = 0;
        ++ip[x].version;
        free.insert(x);
    };
    while (q--) {
        ll t, end;
        string sender, receiver, type;
        int addr;
        cin >> t >> sender >> receiver >> type >> addr >> end;
        while (!events.empty() && get<0>(events.top()) <= t) {
            auto [time, x, version] = events.top();
            events.pop();
            if (version != ip[x].version)
                continue;
            if (ip[x].state == 1)
                clear(x);
            else if (ip[x].state == 2) {
                ip[x].state = 3;
                ip[x].expiry = 0;
                expired.insert(x);
            }
        }
        if (receiver != host && receiver != "*" && type != "REQ")
            continue;
        if (type != "DIS" && type != "REQ")
            continue;
        if (receiver == "*" && type != "DIS")
            continue;
        if (receiver == host && type == "DIS")
            continue;
        if (type == "REQ" && receiver != host) {
            auto it = owned.find(sender);
            if (it != owned.end() && ip[it->second].state == 1)
                clear(it->second);
            continue;
        }
        if (type == "DIS") {
            auto it = owned.find(sender);
            if (it != owned.end())
                addr = it->second;
            else if (!free.empty())
                addr = *free.begin();
            else if (!expired.empty())
                addr = *expired.begin();
            else
                continue;
            if (!ip[addr].owner.empty())
                owned.erase(ip[addr].owner);
            ip[addr].owner = sender;
            owned[sender] = addr;
            ip[addr].state = 1;
        } else {
            if (addr < 1 || addr > n || ip[addr].owner != sender) {
                cout << host << ' ' << sender << " NAK " << addr << " 0\n";
                continue;
            }
            ip[addr].state = 2;
        }
        free.erase(addr);
        expired.erase(addr);
        ip[addr].expiry = end == 0 ? t + def : t + clamp(end - t, lo, hi);
        ++ip[addr].version;
        events.push({ip[addr].expiry, addr, ip[addr].version});
        cout << host << ' ' << sender << ' ' << (type == "DIS" ? "OFR" : "ACK") << ' ' << addr
             << ' ' << ip[addr].expiry << '\n';
    }
}
