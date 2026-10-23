#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct Order {
    string type;
    int price = 0;
    long long quantity = 0;
    bool active = true;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Order> orders(1);
    string type;
    while (cin >> type) {
        Order o;
        o.type = type;
        if (type == "cancel") {
            int i;
            cin >> i;
            orders[i].active = false;
            o.active = false;
        } else {
            string p;
            cin >> p >> o.quantity;
            size_t dot = p.find('.');
            o.price = stoi(p.substr(0, dot)) * 100 + stoi(p.substr(dot + 1));
        }
        orders.push_back(o);
    }
    map<int, pair<long long, long long>> levels;
    long long buyers = 0;
    for (auto o : orders)
        if (o.active && o.quantity) {
            auto &b = levels[o.price];
            if (o.type == "buy") {
                b.first += o.quantity;
                buyers += o.quantity;
            } else
                b.second += o.quantity;
        }
    long long sellers = 0, best = -1;
    int price = 0;
    for (auto [p, v] : levels) {
        sellers += v.second;
        long long volume = min(buyers, sellers);
        if (volume >= best) {
            best = volume;
            price = p;
        }
        buyers -= v.first;
    }
    cout << price / 100 << '.' << setfill('0') << setw(2) << price % 100 << ' ' << max(0LL, best)
         << '\n';
}
