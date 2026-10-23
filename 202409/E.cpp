#include <algorithm>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;
struct Node {
    int l = 0, r = 0, size = 1, color = 0, first = 0, last = 0, runs = 1;
    unsigned priority = 0;
};
vector<Node> t(1);
int sizeOf(int u) {
    return u ? t[u].size : 0;
}
void pull(int u) {
    auto &x = t[u];
    x.size = 1 + sizeOf(x.l) + sizeOf(x.r);
    x.first = x.l ? t[x.l].first : x.color;
    x.last = x.r ? t[x.r].last : x.color;
    x.runs = 1 + (x.l ? t[x.l].runs - (t[x.l].last == x.color) : 0) +
             (x.r ? t[x.r].runs - (t[x.r].first == x.color) : 0);
}
void split(int u, int key, int &a, int &b) {
    if (!u) {
        a = b = 0;
        return;
    }
    if (u <= key) {
        a = u;
        split(t[u].r, key, t[u].r, b);
        pull(u);
    } else {
        b = u;
        split(t[u].l, key, a, t[u].l);
        pull(u);
    }
}
int join(int a, int b) {
    if (!a || !b)
        return a | b;
    if (t[a].priority < t[b].priority) {
        t[a].r = join(t[a].r, b);
        pull(a);
        return a;
    }
    t[b].l = join(a, t[b].l);
    pull(b);
    return b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    t.resize(n + 1);
    vector<int> roots(k + 2);
    vector<unordered_map<int, int>> freq(k + 2);
    mt19937 rng(94127);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i].color;
        t[i].first = t[i].last = t[i].color;
        t[i].priority = rng();
        roots[1] = join(roots[1], i);
        ++freq[1][t[i].color];
    }
    for (int id = 2; id <= k + 1; ++id) {
        int x, l, r, a, b, c;
        cin >> x >> l >> r;
        split(roots[x], r, b, c);
        split(b, l - 1, a, b);
        roots[x] = join(a, c);
        roots[id] = b;
        int small = id, large = x;
        if (sizeOf(roots[x]) < sizeOf(roots[id])) {
            freq[x].swap(freq[id]);
            small = x;
            large = id;
        }
        vector<int> stack;
        if (roots[small])
            stack.push_back(roots[small]);
        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            int color = t[u].color;
            ++freq[small][color];
            auto it = freq[large].find(color);
            if (--it->second == 0)
                freq[large].erase(it);
            if (t[u].l)
                stack.push_back(t[u].l);
            if (t[u].r)
                stack.push_back(t[u].r);
        }
        cout << freq[id].size() << ' ' << (roots[id] ? t[roots[id]].runs : 0) << '\n';
    }
}
