#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using i64 = long long;
struct Queue {
    i64 start, length, next = 0;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<Queue>> processes(n + 1);
    map<i64, i64> free_by_start;
    set<pair<i64, i64>> free_by_size;
    i64 tail = 0;
    auto erase = [&](map<i64, i64>::iterator it) {
        free_by_size.erase({it->second, it->first});
        free_by_start.erase(it);
    };
    auto insert = [&](i64 l, i64 length) {
        if (length) {
            free_by_start[l] = length;
            free_by_size.insert({length, l});
        }
    };
    while (q--) {
        string op;
        int p;
        cin >> op >> p;
        if (op == "new") {
            i64 length, start;
            cin >> length;
            auto it = free_by_size.lower_bound({length, -1});
            if (it == free_by_size.end()) {
                start = tail;
                tail += length;
            } else {
                auto [available, l] = *it;
                start = l;
                erase(free_by_start.find(l));
                insert(l + length, available - length);
            }
            processes[p].push_back({start, length, 0});
            cout << start << '\n';
        } else if (op == "send") {
            i64 sum = 0;
            for (auto &queue : processes[p]) {
                sum += queue.start + queue.next;
                queue.next = (queue.next + 1) % queue.length;
            }
            cout << sum << '\n';
        } else {
            int index;
            cin >> index;
            --index;
            auto queue = processes[p][index];
            processes[p].erase(processes[p].begin() + index);
            i64 l = queue.start, r = l + queue.length;
            auto after = free_by_start.lower_bound(l);
            if (after != free_by_start.begin()) {
                auto before = prev(after);
                if (before->first + before->second == l) {
                    l = before->first;
                    erase(before);
                }
            }
            after = free_by_start.lower_bound(r);
            if (after != free_by_start.end() && after->first == r) {
                r += after->second;
                erase(after);
            }
            if (r == tail)
                tail = l;
            else
                insert(l, r - l);
        }
    }
}
