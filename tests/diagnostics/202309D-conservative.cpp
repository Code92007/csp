#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <set>
#include <utility>
#include <vector>
using namespace std;
using i64 = long long;
using Point = pair<i64, i64>;

struct Entry {
    Point key;
    int employee;
    bool operator<(const Entry &other) const { return key < other.key; }
};
using Tree = set<Entry>;

array<Point, 4> keys(i64 x, i64 y) {
    return {Point{y, x}, Point{x, y}, Point{x - y, x}, Point{x + y, x}};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n, m;
    int p, q;
    cin >> n >> m >> p >> q;
    vector<Point> position(p + 1);
    vector<array<Tree::iterator, 4>> at(p + 1);
    array<Tree, 4> lines;
    for (int i = 1; i <= p; ++i) {
        cin >> position[i].first >> position[i].second;
        auto key = keys(position[i].first, position[i].second);
        for (int j = 0; j < 4; ++j)
            at[i][j] = lines[j].insert({key[j], i}).first;
    }
    const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    const int positiveDirection[4] = {0, 2, 1, 7};
    while (q--) {
        i64 u, v;
        int t;
        cin >> u >> v >> t;
        t %= 8;
        if (t == 0) continue;
        i64 boundary = min({u - 1, n - u, v - 1, m - v});
        i64 distance = boundary + 1;
        int nearest[8] = {};
        i64 distances[8] = {};
        auto key = keys(u, v);
        for (int j = 0; j < 4; ++j) {
            auto after = lines[j].upper_bound({key[j], 0});
            auto accept = [&](Tree::iterator it, int direction) {
                if (it->key.first != key[j].first) return;
                i64 delta = it->key.second - key[j].second;
                if (delta < 0) delta = -delta;
                nearest[direction] = it->employee;
                distances[direction] = delta;
                distance = min(distance, delta);
            };
            if (after != lines[j].end()) accept(after, positiveDirection[j]);
            if (after != lines[j].begin()) {
                auto before = prev(after);
                if (before->key == key[j]) {
                    if (before == lines[j].begin()) continue;
                    --before;
                }
                accept(before, (positiveDirection[j] + 4) % 8);
            }
        }
        if (distance > boundary) continue;
        int moved[8], direction[8], count = 0;
        for (int d = 0; d < 8; ++d)
            if (nearest[d] && distances[d] == distance) {
                moved[count] = nearest[d];
                direction[count++] = (d + t) % 8;
            }
        // Keep each node attached to its employee identity. Remove every
        // moving employee before inserting any destination, as in the baseline.
        array<array<Tree::node_type, 4>, 8> detached;
        for (int i = 0; i < count; ++i)
            for (int j = 0; j < 4; ++j)
                detached[i][j] = lines[j].extract(at[moved[i]][j]);
        for (int i = 0; i < count; ++i) {
            int id = moved[i], d = direction[i];
            position[id] = {u + distance * dx[d], v + distance * dy[d]};
            auto newKey = keys(position[id].first, position[id].second);
            for (int j = 0; j < 4; ++j) {
                detached[i][j].value().key = newKey[j];
                at[id][j] = lines[j].insert(std::move(detached[i][j])).position;
            }
        }
    }
    i64 answer = 0;
    for (int i = 1; i <= p; ++i)
        answer ^= i * position[i].first + position[i].second;
    cout << answer << '\n';
}
