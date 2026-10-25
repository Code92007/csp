#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <iterator>
#include <set>
#include <utility>
#include <vector>
using namespace std;

class FastInput {
    static constexpr int SIZE = 1 << 16;
    char buffer[SIZE];
    int pos = 0, length = 0;
    int get() {
        if (pos == length) {
            length = int(fread(buffer, 1, SIZE, stdin));
            pos = 0;
            if (!length) return EOF;
        }
        return buffer[pos++];
    }
public:
    int read() {
        int c = get(), value = 0;
        while (c <= ' ' && c != EOF) c = get();
        while (c >= '0' && c <= '9') {
            value = value * 10 + c - '0';
            c = get();
        }
        return value;
    }
};

constexpr uint64_t MASK = (uint64_t(1) << 30) - 1;
struct Entry {
    uint64_t key;
    int slot;
    bool operator<(const Entry &other) const { return key < other.key; }
};
using Tree = set<Entry>;
struct Slot {
    int x, y, employee;
    array<Tree::iterator, 4> at;
};
array<uint64_t, 4> keys(int x, int y) {
    return {(uint64_t(y) << 30) | uint32_t(x),
            (uint64_t(x) << 30) | uint32_t(y),
            (uint64_t(x - y + 1000000000) << 30) | uint32_t(x),
            (uint64_t(x + y) << 30) | uint32_t(x)};
}

int main() {
    FastInput in;
    int n = in.read(), m = in.read(), p = in.read(), q = in.read();
    vector<Slot> slots(p + 1);
    array<Tree, 4> lines;
    for (int i = 1; i <= p; ++i) {
        Slot &slot = slots[i];
        slot.x = in.read(); slot.y = in.read(); slot.employee = i;
        auto key = keys(slot.x, slot.y);
        for (int j = 0; j < 4; ++j)
            slot.at[j] = lines[j].insert({key[j], i}).first;
    }
    const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    const int positiveDirection[4] = {0, 2, 1, 7};
    while (q--) {
        int u = in.read(), v = in.read(), t = in.read();
        int boundary = min({u - 1, n - u, v - 1, m - v});
        if (!boundary) continue;
        int distance = boundary + 1;
        int nearest[8] = {}, distances[8] = {};
        auto key = keys(u, v);
        for (int j = 0; j < 4; ++j) {
            auto after = lines[j].upper_bound({key[j], 0});
            auto accept = [&](Tree::iterator it, int direction) {
                if ((it->key >> 30) != (key[j] >> 30)) return;
                int delta = int(it->key & MASK) - int(key[j] & MASK);
                if (delta < 0) delta = -delta;
                nearest[direction] = it->slot;
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
                accept(before, (positiveDirection[j] + 4) & 7);
            }
        }
        if (distance > boundary) continue;

        int occupied[8] = {}, destinationEmployee[8] = {};
        for (int d = 0; d < 8; ++d) {
            if (nearest[d] && distances[d] == distance) {
                occupied[d] = nearest[d];
                destinationEmployee[(d + t) & 7] = slots[nearest[d]].employee;
            }
        }
        int vacated[4], targets[4], count = 0, targetCount = 0;
        for (int d = 0; d < 8; ++d) {
            if (occupied[d] && destinationEmployee[d]) {
                // The position stays occupied: only its employee label changes.
                slots[occupied[d]].employee = destinationEmployee[d];
            } else if (occupied[d]) {
                vacated[count++] = occupied[d];
            } else if (destinationEmployee[d]) {
                targets[targetCount++] = d;
            }
        }
        // Two subsets of an 8-element set with equal cardinality differ in
        // at most 4 positions on each side. Reuse the vacated position slots.
        array<array<Tree::node_type, 4>, 4> detached;
        for (int i = 0; i < count; ++i)
            for (int j = 0; j < 4; ++j)
                detached[i][j] = lines[j].extract(slots[vacated[i]].at[j]);
        for (int i = 0; i < count; ++i) {
            int id = vacated[i], d = targets[i];
            Slot &slot = slots[id];
            slot.x = u + distance * dx[d];
            slot.y = v + distance * dy[d];
            slot.employee = destinationEmployee[d];
            auto newKey = keys(slot.x, slot.y);
            for (int j = 0; j < 4; ++j) {
                detached[i][j].value().key = newKey[j];
                slot.at[j] = lines[j].insert(std::move(detached[i][j])).position;
            }
        }
    }
    long long answer = 0;
    for (int i = 1; i <= p; ++i)
        answer ^= 1LL * slots[i].employee * slots[i].x + slots[i].y;
    printf("%lld\n", answer);
}
