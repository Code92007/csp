#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using i64 = long long;
using Point = pair<i64, i64>;
uint64_t code(i64 x, i64 y) {
    return (uint64_t(x) << 32) | uint64_t(y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n, m;
    int p, q;
    cin >> n >> m >> p >> q;
    vector<Point> position(p + 1);
    array<set<Point>, 4> lines;
    unordered_map<uint64_t, int> who;
    who.reserve(p * 2);
    auto keys = [](i64 x, i64 y) {
        return array<Point, 4>{Point{y, x}, Point{x, y}, Point{x - y, x}, Point{x + y, x}};
    };
    auto insert = [&](int id) {
        auto [x, y] = position[id];
        auto k = keys(x, y);
        for (int j = 0; j < 4; ++j)
            lines[j].insert(k[j]);
        who[code(x, y)] = id;
    };
    auto erase = [&](int id) {
        auto [x, y] = position[id];
        auto k = keys(x, y);
        for (int j = 0; j < 4; ++j)
            lines[j].erase(k[j]);
        who.erase(code(x, y));
    };
    for (int i = 1; i <= p; ++i) {
        cin >> position[i].first >> position[i].second;
        insert(i);
    }
    const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    while (q--) {
        i64 u, v;
        int t;
        cin >> u >> v >> t;
        i64 boundary = min({u - 1, n - u, v - 1, m - v}), distance = boundary + 1;
        auto k = keys(u, v);
        for (int j = 0; j < 4; ++j) {
            auto [line, coordinate] = k[j];
            auto after = lines[j].upper_bound(k[j]);
            if (after != lines[j].end() && after->first == line)
                distance = min(distance, after->second - coordinate);
            auto before = lines[j].lower_bound(k[j]);
            if (before != lines[j].begin()) {
                --before;
                if (before->first == line)
                    distance = min(distance, coordinate - before->second);
            }
        }
        if (distance > boundary)
            continue;
        vector<pair<int, int>> moved;
        for (int d = 0; d < 8; ++d) {
            auto it = who.find(code(u + distance * dx[d], v + distance * dy[d]));
            if (it != who.end())
                moved.push_back({it->second, (d + t) % 8});
        }
        for (auto [id, d] : moved)
            erase(id);
        for (auto [id, d] : moved) {
            position[id] = {u + distance * dx[d], v + distance * dy[d]};
            insert(id);
        }
    }
    i64 answer = 0;
    for (int i = 1; i <= p; ++i)
        answer ^= i * position[i].first + position[i].second;
    cout << answer << '\n';
}
