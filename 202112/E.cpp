#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdint>
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
struct Item {
    int id, low, high;
};

class Counter {
    int n, k1, k2;
    int blocks;
    vector<int> bit;
    vector<uint64_t> occupied, complete;
    vector<int> prefix;
    vector<Item> a, b, temporary;

    void sortBy(vector<Item> &items, bool high) {
        if (items.size() < 2048) {
            if (high)
                sort(items.begin(), items.end(), [](const Item &x, const Item &y) { return x.high < y.high; });
            else
                sort(items.begin(), items.end(), [](const Item &x, const Item &y) { return x.id < y.id; });
            return;
        }
        // Both keys are vertex labels <= 500000, hence fit in 19 bits.
        temporary.resize(items.size());
        for (int shift : {0, 10}) {
            array<int, 1024> count{};
            for (const Item &item : items)
                ++count[((high ? item.high : item.id) >> shift) & 1023];
            int total = 0;
            for (int &value : count) {
                int size = value;
                value = total;
                total += size;
            }
            for (const Item &item : items)
                temporary[count[((high ? item.high : item.id) >> shift) & 1023]++] = item;
            items.swap(temporary);
        }
    }
    long long sweep() {
        if (a.empty() || b.empty()) return 0;
        long long answer = 0;
        if (min(a.size(), b.size()) <= 24) {
            for (const Item &x : a)
                for (const Item &y : b)
                    if (x.id < y.id && x.high <= y.id + k2 && x.id <= y.low + k1)
                        ++answer;
            return answer;
        }
        int maxHigh = 0, minHigh = n + 1;
        for (const Item &x : a) { maxHigh = max(maxHigh, x.high); minHigh = min(minHigh, x.high); }
        int fullyActive = 0;
        for (const Item &y : b) fullyActive += y.id + k2 >= maxHigh;
        // These queries accept every A by the high-bound condition. Answer
        // them from a static bitmap before sorting or updating the Fenwick.
        // The threshold charges the O(blocks) prefix build to enough queries.
        if (fullyActive >= max(32, blocks / 8)) {
            for (const Item &x : a) complete[(x.id - 1) >> 6] |= uint64_t(1) << ((x.id - 1) & 63);
            prefix[0] = 0;
            for (int i = 0; i < blocks; ++i) prefix[i + 1] = prefix[i] + __builtin_popcountll(complete[i]);
            size_t kept = 0;
            int largestThreshold = 0;
            for (const Item &y : b) {
                if (y.id + k2 >= maxHigh) {
                    int limit = min(y.id - 1, y.low + k1);
                    answer += prefix[limit >> 6] + __builtin_popcountll(complete[limit >> 6] & ((uint64_t(1) << (limit & 63)) - 1));
                } else {
                    b[kept++] = y;
                    largestThreshold = max(largestThreshold, y.id + k2);
                }
            }
            b.resize(kept);
            for (const Item &x : a) complete[(x.id - 1) >> 6] = 0;
            if (b.empty()) return answer;
            kept = 0; minHigh = n + 1; maxHigh = 0;
            for (const Item &x : a) if (x.high <= largestThreshold) {
                a[kept++] = x;
                minHigh = min(minHigh, x.high); maxHigh = max(maxHigh, x.high);
            }
            a.resize(kept);
            if (a.empty()) return answer;
            if (min(a.size(), b.size()) <= 24) {
                for (const Item &x : a)
                    for (const Item &y : b)
                        if (x.id < y.id && x.high <= y.id + k2 && x.id <= y.low + k1) ++answer;
                return answer;
            }
        }
        if (minHigh != maxHigh) sortBy(a, true);
        sortBy(b, false);
        size_t inserted = 0;
        int lastLimit = -1, lastInserted = -1, lastAnswer = 0;
        for (const Item &y : b) {
            int limit = min(y.id - 1, y.low + k1);
            int full = limit >> 6, remainder = limit & 63;
            while (inserted < a.size() && a[inserted].high <= y.id + k2) {
                int label = a[inserted++].id - 1;
                int block = label >> 6;
                // Labels are unique. A word records membership within 64
                // labels; the much smaller Fenwick stores whole-word counts.
                occupied[block] |= uint64_t(1) << (label & 63);
                for (int x = block + 1; x <= blocks; x += x & -x)
                    ++bit[x];
            }
            if (lastLimit != limit || lastInserted != int(inserted)) {
                lastAnswer = __builtin_popcountll(occupied[full] & ((uint64_t(1) << remainder) - 1));
                for (int x = full; x > 0; x -= x & -x) lastAnswer += bit[x];
                lastLimit = limit; lastInserted = int(inserted);
            }
            answer += lastAnswer;
        }
        // Every updated Fenwick entry is nonnegative. If a reset chain hits
        // zero, that node and all its ancestors were already reset together.
        for (size_t i = 0; i < inserted; ++i) {
            int block = (a[i].id - 1) >> 6;
            if (!occupied[block]) continue;
            occupied[block] = 0;
            for (int x = block + 1; x <= blocks && bit[x]; x += x & -x)
                bit[x] = 0;
        }
        return answer;
    }

public:
    Counter(int n_, int k1_, int k2_) : n(n_), k1(k1_), k2(k2_),
        blocks((n + 63) / 64), bit(blocks + 1), occupied(blocks + 1),
        complete(blocks + 1), prefix(blocks + 1) {
        a.reserve(n); b.reserve(n); temporary.reserve(n);
    }
    long long count(const Item *items, int size) {
        if (size < 2) return 0;
        a.clear(); b.clear();
        for (int i = 0; i < size; ++i) {
            Item x = items[i];
            if (x.low >= x.id - k1) a.push_back(x);
            if (x.high <= x.id + k2) b.push_back(x);
        }
        return sweep();
    }
    long long cross(const Item *left, int nl, const Item *right, int nr) {
        a.clear(); b.clear();
        for (int i = 0; i < nl; ++i)
            if (left[i].low >= left[i].id - k1) a.push_back(left[i]);
        for (int i = 0; i < nr; ++i)
            if (right[i].high <= right[i].id + k2) b.push_back(right[i]);
        return sweep();
    }
    long long crossBoth(const Item *left, int nl, const Item *right, int nr) {
        return cross(left, nl, right, nr) + cross(right, nr, left, nl);
    }
};

int main() {
    FastInput in;
    int n = in.read(), k1 = in.read(), k2 = in.read();
    vector<int> head(n + 2), adjacent(2 * (n - 1));
    {
        vector<pair<int, int>> inputEdges(n - 1);
        for (auto &edge : inputEdges) {
            edge.first = in.read(); edge.second = in.read();
            ++head[edge.first]; ++head[edge.second];
        }
        int totalEdges = 0;
        for (int i = 1; i <= n + 1; ++i) {
            int degree = head[i]; head[i] = totalEdges; totalEdges += degree;
        }
        vector<int> cursor = head;
        for (const auto &edge : inputEdges) {
            adjacent[cursor[edge.first]++] = edge.second;
            adjacent[cursor[edge.second]++] = edge.first;
        }
    }
    if (k1 >= n - 1 && k2 >= n - 1) {
        printf("%lld\n", 1LL * n * (n + 1) / 2);
        return 0;
    }
    vector<int> label(n + 1);
    {
        // Graph storage uses DFS-order indices for locality. label[u] always
        // retains the original problem label; no path condition uses u itself.
        vector<int> mapping(n + 1), stack{1};
        mapping[1] = -1;
        int nextId = 0;
        while (!stack.empty()) {
            int u = stack.back(); stack.pop_back();
            mapping[u] = ++nextId; label[nextId] = u;
            for (int e = head[u]; e < head[u + 1]; ++e) {
                int v = adjacent[e];
                if (!mapping[v]) { mapping[v] = -1; stack.push_back(v); }
            }
        }
        vector<int> newHead(n + 2), newAdjacent(adjacent.size());
        int nextEdge = 0;
        for (int u = 1; u <= n; ++u) {
            newHead[u] = nextEdge;
            for (int e = head[label[u]]; e < head[label[u] + 1]; ++e)
                newAdjacent[nextEdge++] = mapping[adjacent[e]];
        }
        newHead[n + 1] = nextEdge;
        head.swap(newHead); adjacent.swap(newAdjacent);
    }
    Counter counter(n, k1, k2);
    vector<int> parent(n + 1), size(n + 1), largest(n + 1), order, components{1};
    vector<unsigned char> removed(n + 1);
    vector<Item> all;
    vector<pair<int, int>> branches;
    order.reserve(n); all.reserve(n); components.reserve(n);
    long long answer = n;
    while (!components.empty()) {
        int start = components.back(); components.pop_back();
        order.clear(); order.push_back(start); parent[start] = 0;
        int minLabel = n + 1, maxLabel = 0;
        for (size_t i = 0; i < order.size(); ++i) {
            int u = order[i];
            minLabel = min(minLabel, label[u]); maxLabel = max(maxLabel, label[u]);
            size[u] = 1; largest[u] = 0;
            for (int e = head[u]; e < head[u + 1]; ++e) {
                int v = adjacent[e];
                if (!removed[v] && v != parent[u]) {
                    parent[v] = u;
                    order.push_back(v);
                }
            }
        }
        int total = int(order.size()), centroid = start;
        // For x < y, x <= maxLabel-1 and y >= minLabel+1. This bound makes
        // every path in this component valid, so its descendants need no work.
        if (min(k1, k2) >= maxLabel - minLabel - 1) {
            answer += 1LL * total * (total - 1) / 2;
            continue;
        }
        for (int i = total - 1; i >= 0; --i) {
            int u = order[i], p = parent[u];
            if (max(largest[u], total - size[u]) <= total / 2) centroid = u;
            if (p) {
                size[p] += size[u];
                largest[p] = max(largest[p], size[u]);
            }
        }
        branches.clear();
        for (int e = head[centroid]; e < head[centroid + 1]; ++e) {
            int v = adjacent[e];
            if (!removed[v]) branches.push_back({parent[v] == centroid ? size[v] : total - size[centroid], v});
        }
        if (branches.size() <= 3)
            sort(branches.begin(), branches.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
                return x.first > y.first;
            });
        int centreLabel = label[centroid];
        all.clear(); all.push_back({centreLabel, centreLabel, centreLabel});
        order.clear(); order.push_back(centroid);
        for (const auto &branch : branches) {
            int neighbor = branch.second;
            int begin = int(all.size());
            parent[neighbor] = centroid;
            order.push_back(neighbor);
            all.push_back({label[neighbor], min(label[neighbor], centreLabel), max(label[neighbor], centreLabel)});
            for (size_t i = begin; i < all.size(); ++i) {
                Item item = all[i];
                int u = order[i];
                for (int f = head[u]; f < head[u + 1]; ++f) {
                    int v = adjacent[f];
                    if (!removed[v] && v != parent[u]) {
                        parent[v] = u;
                        order.push_back(v);
                        all.push_back({label[v], min(item.low, label[v]), max(item.high, label[v])});
                    }
                }
            }
            if (branches.size() > 3)
                answer -= counter.count(all.data() + begin, int(all.size()) - begin);
        }
        if (branches.size() <= 3) {
            // Count centroid endpoints directly. For two/three branches,
            // disjoint cross-group counts avoid the repeated all-minus-own
            // work; with three branches, combine the largest against the rest.
            for (size_t i = 1; i < all.size(); ++i) {
                const Item &v = all[i];
                if (v.low >= min(centreLabel, v.id) - k1 && v.high <= max(centreLabel, v.id) + k2)
                    ++answer;
            }
            if (branches.size() >= 2) {
                int first = branches[0].first;
                answer += counter.crossBoth(all.data() + 1, first, all.data() + first + 1, total - first - 1);
            }
            if (branches.size() == 3) {
                int first = branches[0].first, second = branches[1].first;
                answer += counter.crossBoth(all.data() + first + 1, second,
                                            all.data() + first + second + 1, branches[2].first);
            }
        } else {
            answer += counter.count(all.data(), int(all.size()));
        }
        removed[centroid] = 1;
        for (int e = head[centroid]; e < head[centroid + 1]; ++e)
            if (!removed[adjacent[e]]) components.push_back(adjacent[e]);
    }
    printf("%lld\n", answer);
}
