#include <algorithm>
#include <cstdio>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class FastInput {
    static constexpr int SIZE = 1 << 16;
    char buffer[SIZE];
    int at = 0, length = 0;
    int next() {
        if (at == length) {
            length = int(fread(buffer, 1, SIZE, stdin));
            at = 0;
            if (!length) return EOF;
        }
        return buffer[at++];
    }
public:
    int read() {
        int c = next();
        while (c <= ' ' && c != EOF) c = next();
        int x = 0;
        while ('0' <= c && c <= '9') {
            x = x * 10 + c - '0';
            c = next();
        }
        return x;
    }
};
struct Rectangle { int xl, xr, yl, yr, value; };
vector<Rectangle> rectangles;

// Each envelope occupies [coordinates, iterative range-maximum tree] in one arena.
vector<int> arena;
struct Envelope {
    int offset = 0, size = 0;
    int coordinate(int i) const { return arena[offset + i]; }
    int value(int i) const { return arena[offset + 2 * size + i]; }
    int bound() const { return size ? arena[offset + size + 1] : 0; }
    int query(int l, int r) const {
        if (!size || r < coordinate(0) || l >= coordinate(size - 1)) return 0;
        auto begin = arena.begin() + offset;
        int a = max(0, int(upper_bound(begin, begin + size, l) - begin) - 1);
        int b = int(upper_bound(begin, begin + size, r) - begin);
        int answer = 0, tree = offset + size;
        for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
            if (a & 1) answer = max(answer, arena[tree + a++]);
            if (b & 1) answer = max(answer, arena[tree + --b]);
        }
        return answer;
    }
};
struct Node { Envelope cover, all; };
vector<Node> nodes;

Envelope saveEnvelope(const vector<int> &coordinates, const vector<int> &values) {
    int size = int(coordinates.size()), offset = int(arena.size());
    if (!size) return {};
    arena.resize(offset + 3 * size);
    copy(coordinates.begin(), coordinates.end(), arena.begin() + offset);
    copy(values.begin(), values.end(), arena.begin() + offset + 2 * size);
    int tree = offset + size;
    for (int i = size - 1; i; --i)
        arena[tree + i] = max(arena[tree + 2 * i], arena[tree + 2 * i + 1]);
    return {offset, size};
}
int findNext(vector<int> &next, int x) {
    while (next[x] != x) {
        next[x] = next[next[x]];
        x = next[x];
    }
    return x;
}
Envelope buildCover(const vector<int> &ids, int first, int last) {
    if (first == last) return {};
    if (last - first == 1) {
        const auto &a = rectangles[ids[first]];
        return saveEnvelope({a.yl, a.yr + 1}, {a.value, 0});
    }
    vector<int> coordinates;
    coordinates.reserve(2 * (last - first));
    for (int i = first; i < last; ++i) {
        const auto &a = rectangles[ids[i]];
        coordinates.push_back(a.yl);
        coordinates.push_back(a.yr + 1);
    }
    sort(coordinates.begin(), coordinates.end());
    coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());
    int size = int(coordinates.size());
    vector<int> next(size + 1), values(size);
    iota(next.begin(), next.end(), 0);
    // IDs are in decreasing weight order: each elementary interval is painted once.
    for (int i = first; i < last; ++i) {
        const auto &a = rectangles[ids[i]];
        int l = int(lower_bound(coordinates.begin(), coordinates.end(), a.yl) - coordinates.begin());
        int r = int(lower_bound(coordinates.begin(), coordinates.end(), a.yr + 1) - coordinates.begin());
        for (int p = findNext(next, l); p < r; p = findNext(next, p)) {
            values[p] = a.value;
            next[p] = findNext(next, p + 1);
        }
    }
    int written = 0, previous = 0;
    for (int i = 0; i < size; ++i)
        if (values[i] != previous) {
            previous = values[i];
            coordinates[written] = coordinates[i];
            values[written++] = previous;
        }
    coordinates.resize(written);
    values.resize(written);
    return saveEnvelope(coordinates, values);
}

Envelope mergeEnvelopes(Envelope a, Envelope b, Envelope c) {
    Envelope inputs[3] = {a, b, c};
    int nonempty = 0, single = 0;
    for (int i = 0; i < 3; ++i) if (inputs[i].size) ++nonempty, single = i;
    if (!nonempty) return {};
    if (nonempty == 1) return inputs[single];
    int at[3] = {}, current[3] = {}, previous = 0;
    vector<int> coordinates, values;
    int total = a.size + b.size + c.size;
    coordinates.reserve(total);
    values.reserve(total);
    while (true) {
        int x = 1000000000;
        for (int i = 0; i < 3; ++i)
            if (at[i] < inputs[i].size) x = min(x, inputs[i].coordinate(at[i]));
        if (x == 1000000000) break;
        for (int i = 0; i < 3; ++i)
            if (at[i] < inputs[i].size && inputs[i].coordinate(at[i]) == x)
                current[i] = inputs[i].value(at[i]++);
        int value = max(current[0], max(current[1], current[2]));
        if (value != previous) {
            coordinates.push_back(x);
            values.push_back(value);
            previous = value;
        }
    }
    // A dominating child or cover can be shared without another stored copy.
    for (Envelope old : inputs) {
        if (old.size != int(coordinates.size())) continue;
        bool equal = true;
        for (int i = 0; i < old.size && equal; ++i)
            equal = old.coordinate(i) == coordinates[i] && old.value(i) == values[i];
        if (equal) return old;
    }
    return saveEnvelope(coordinates, values);
}

int query(int node, int left, int right, int a, int b, int c, int d, int known) {
    if (nodes[node].all.bound() <= known) return known;
    if (a <= left && right <= b) return max(known, nodes[node].all.query(c, d));
    if (nodes[node].cover.bound() > known) known = max(known, nodes[node].cover.query(c, d));
    int middle = (left + right) / 2;
    bool useLeft = a <= middle, useRight = b > middle;
    if (useLeft && useRight) {
        if (nodes[2 * node].all.bound() >= nodes[2 * node + 1].all.bound()) {
            known = query(2 * node, left, middle, a, b, c, d, known);
            known = query(2 * node + 1, middle + 1, right, a, b, c, d, known);
        } else {
            known = query(2 * node + 1, middle + 1, right, a, b, c, d, known);
            known = query(2 * node, left, middle, a, b, c, d, known);
        }
    } else if (useLeft) {
        known = query(2 * node, left, middle, a, b, c, d, known);
    } else {
        known = query(2 * node + 1, middle + 1, right, a, b, c, d, known);
    }
    return known;
}

int main() {
    FastInput input;
    int n = input.read(), m = input.read(), base = 1, height = 0;
    if (!n) return 0;
    while (base < n) base <<= 1, ++height;
    rectangles.resize(n);
    nodes.resize(2 * base);
    vector<int> order(n), starts(2 * base + 1);
    iota(order.begin(), order.end(), 0);
    long long xRecords = 0, yRecords = 0;
    auto records = [base](int a, int b) {
        int answer = 0;
        for (int l = a + base - 1, r = b + base; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ++answer, ++l;
            if (r & 1) ++answer, --r;
        }
        return answer;
    };
    for (auto &a : rectangles) {
        a.xl = input.read(); a.xr = input.read();
        a.yl = input.read(); a.yr = input.read(); a.value = input.read();
        xRecords += records(a.xl, a.xr);
        yRecords += records(a.yl, a.yr);
    }
    // Either axis is valid. Use the one with fewer canonical insertion records.
    bool swapped = yRecords < xRecords;
    for (auto &a : rectangles) {
        if (swapped) swap(a.xl, a.yl), swap(a.xr, a.yr);
        for (int l = a.xl + base - 1, r = a.xr + base; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ++starts[l++ + 1];
            if (r & 1) ++starts[--r + 1];
        }
    }
    for (int i = 1; i <= 2 * base; ++i) starts[i] += starts[i - 1];
    vector<int> ids(starts.back()), cursor = starts;
    sort(order.begin(), order.end(), [](int a, int b) {
        return rectangles[a].value > rectangles[b].value;
    });
    for (int id : order) {
        const auto &a = rectangles[id];
        for (int l = a.xl + base - 1, r = a.xr + base; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ids[cursor[l]++] = id, ++l;
            if (r & 1) --r, ids[cursor[r]++] = id;
        }
    }
    vector<int>().swap(cursor);
    vector<int>().swap(order);
    // Reserve once to avoid a large old/new-buffer peak during arena growth.
    arena.reserve(size_t(6) * n * (height + 1));
    for (int u = 2 * base - 1; u; --u) {
        nodes[u].cover = buildCover(ids, starts[u], starts[u + 1]);
        nodes[u].all = u >= base ? nodes[u].cover :
            mergeEnvelopes(nodes[u].cover, nodes[2 * u].all, nodes[2 * u + 1].all);
    }
    vector<int>().swap(ids);
    vector<int>().swap(starts);
    vector<Rectangle>().swap(rectangles);
    string output;
    output.reserve(m * 8);
    while (m--) {
        int a = input.read(), b = input.read(), c = input.read(), d = input.read();
        if (swapped) swap(a, c), swap(b, d);
        output += to_string(query(1, 1, base, a, b, c, d, 0));
        output.push_back('\n');
    }
    fwrite(output.data(), 1, output.size(), stdout);
}
