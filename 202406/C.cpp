#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using i64 = long long;
struct TokenNode {
    int token, previous, next;
    i64 weight;
    bool alive = true;
};
struct PairInfo {
    int left, right, version = 0;
    i64 frequency = 0;
    set<int> positions;
};
struct Entry {
    i64 frequency;
    int pair, version;
};
vector<string> vocabulary;
vector<PairInfo> pairs;
struct Worse {
    bool operator()(const Entry &a, const Entry &b) const {
        if (a.frequency != b.frequency)
            return a.frequency < b.frequency;
        const auto &x = pairs[a.pair];
        const auto &y = pairs[b.pair];
        size_t ax = vocabulary[x.left].size(), ay = vocabulary[y.left].size(),
               bx = vocabulary[x.right].size(), by = vocabulary[y.right].size();
        if (ax + bx != ay + by)
            return ax + bx > ay + by;
        if (ax != ay)
            return ax > ay;
        int order = vocabulary[x.left].compare(vocabulary[y.left]);
        if (order)
            return order > 0;
        order = vocabulary[x.right].compare(vocabulary[y.right]);
        if (order)
            return order > 0;
        return a.pair > b.pair;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, target;
    cin >> n >> target;
    vector<string> words(n);
    vector<i64> frequency(n);
    set<char> alphabet;
    for (int i = 0; i < n; ++i) {
        cin >> words[i] >> frequency[i];
        for (char c : words[i])
            alphabet.insert(c);
    }
    unordered_map<string, int> token_id;
    for (char c : alphabet) {
        string s(1, c);
        token_id[s] = vocabulary.size();
        vocabulary.push_back(s);
        cout << s << '\n';
    }
    vector<TokenNode> nodes;
    for (int i = 0; i < n; ++i) {
        int start = nodes.size();
        for (char c : words[i]) {
            int index = nodes.size();
            nodes.push_back({token_id[string(1, c)], index == start ? -1 : index - 1, index + 1,
                             frequency[i], true});
        }
        nodes.back().next = -1;
    }
    unordered_map<uint64_t, int> pair_id;
    priority_queue<Entry, vector<Entry>, Worse> heap;
    auto pair_index = [&](int left, int right) {
        uint64_t key = (uint64_t(left) << 32) | uint64_t(right);
        auto it = pair_id.find(key);
        if (it != pair_id.end())
            return it->second;
        int id = pairs.size();
        pairs.push_back({left, right, 0, 0, {}});
        pair_id[key] = id;
        return id;
    };
    auto change = [&](int position, int sign) {
        if (position < 0 || nodes[position].next < 0)
            return;
        int id = pair_index(nodes[position].token, nodes[nodes[position].next].token);
        auto &p = pairs[id];
        p.frequency += sign * nodes[position].weight;
        ++p.version;
        if (sign == 1)
            p.positions.insert(position);
        else
            p.positions.erase(position);
        if (p.frequency > 0)
            heap.push({p.frequency, id, p.version});
    };
    for (int i = 0; i < int(nodes.size()); ++i)
        change(i, 1);
    int printed = vocabulary.size();
    while (printed < target) {
        while (!heap.empty() && (heap.top().version != pairs[heap.top().pair].version ||
                                 pairs[heap.top().pair].frequency == 0))
            heap.pop();
        if (heap.empty())
            break;
        int chosen = heap.top().pair;
        heap.pop();
        int left_token = pairs[chosen].left, right_token = pairs[chosen].right;
        string joined = vocabulary[left_token] + vocabulary[right_token];
        cout << joined << '\n';
        ++printed;
        int new_token;
        auto it = token_id.find(joined);
        if (it == token_id.end()) {
            new_token = vocabulary.size();
            token_id[joined] = new_token;
            vocabulary.push_back(joined);
        } else
            new_token = it->second;
        vector<int> positions(pairs[chosen].positions.begin(), pairs[chosen].positions.end());
        for (int a : positions) {
            if (!nodes[a].alive || nodes[a].next < 0)
                continue;
            int b = nodes[a].next;
            if (nodes[a].token != left_token || nodes[b].token != right_token)
                continue;
            int before = nodes[a].previous, after = nodes[b].next;
            change(before, -1);
            change(a, -1);
            change(b, -1);
            nodes[a].token = new_token;
            nodes[a].next = after;
            nodes[b].alive = false;
            nodes[b].next = -1;
            if (after >= 0)
                nodes[after].previous = a;
            change(before, 1);
            change(a, 1);
        }
    }
}
