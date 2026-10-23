#include <cmath>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
using i64 = long long;
struct Mirror {
    i64 x1, y1, x2, y2;
    double ratio;
    int slope;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<Mirror> mirrors(m + 1);
    map<pair<i64, i64>, int> horizontal, vertical;
    auto modify = [&](int id, bool insert) {
        const auto &s = mirrors[id];
        for (i64 x = s.x1 + 1; x < s.x2; ++x) {
            i64 y = s.y1 + s.slope * (x - s.x1);
            if (insert) {
                horizontal[{y, x}] = id;
                vertical[{x, y}] = id;
            } else {
                horizontal.erase({y, x});
                vertical.erase({x, y});
            }
        }
    };
    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    for (int op_index = 1; op_index <= m; ++op_index) {
        int op;
        cin >> op;
        if (op == 1) {
            auto &s = mirrors[op_index];
            cin >> s.x1 >> s.y1 >> s.x2 >> s.y2 >> s.ratio;
            if (s.x1 > s.x2) {
                swap(s.x1, s.x2);
                swap(s.y1, s.y2);
            }
            s.slope = s.y2 > s.y1 ? 1 : -1;
            modify(op_index, true);
        } else if (op == 2) {
            int id;
            cin >> id;
            modify(id, false);
        } else {
            i64 x, y, time;
            int direction;
            double intensity;
            cin >> x >> y >> direction >> intensity >> time;
            while (time > 0 && intensity >= 1) {
                bool is_horizontal = direction % 2 == 0, positive = direction < 2;
                auto &points = is_horizontal ? horizontal : vertical;
                i64 line = is_horizontal ? y : x, current = is_horizontal ? x : y;
                auto it = points.end();
                if (positive)
                    it = points.upper_bound({line, current});
                else {
                    auto next = points.lower_bound({line, current});
                    if (next != points.begin())
                        it = prev(next);
                }
                if (it == points.end() || it->first.first != line ||
                    abs(it->first.second - current) > time) {
                    x += dx[direction] * time;
                    y += dy[direction] * time;
                    time = 0;
                    break;
                }
                i64 distance = abs(it->first.second - current);
                x += dx[direction] * distance;
                y += dy[direction] * distance;
                time -= distance;
                const auto &s = mirrors[it->second];
                intensity *= s.ratio;
                direction ^= s.slope == 1 ? 1 : 3;
            }
            if (intensity < 1)
                cout << "0 0 0\n";
            else
                cout << x << ' ' << y << ' ' << i64(floor(intensity)) << '\n';
        }
    }
}
