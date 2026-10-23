#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct Hash {
    size_t operator()(uint64_t x) const {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<uint32_t> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        uint32_t x; cin >> x;
        prefix[i] = x ^ (i >= 2 ? prefix[i - 2] : 0);
    }
    vector<int> end(n + 3, n + 1);
    {
        unordered_map<uint32_t, int, Hash> nearest[2];
        nearest[0].reserve(n / 2 + 1); nearest[1].reserve(n / 2 + 1);
        for (int i = n; i >= 1; --i) {
            auto& table = nearest[i & 1];
            table[prefix[i]] = i;
            uint32_t target = i >= 2 ? prefix[i - 2] : 0;
            auto it = table.find(target);
            if (it != table.end()) end[i] = it->second;
            end[i] = min(end[i], end[i + 1]);
        }
    }
    int levels = 1;
    while ((1 << levels) <= n) ++levels;
    vector<vector<int>> jump(levels, vector<int>(n + 3, n + 2));
    for (int i = 1; i <= n; ++i) jump[0][i] = end[i] + 1;
    for (int b = 1; b < levels; ++b)
        for (int i = 1; i <= n; ++i) jump[b][i] = jump[b - 1][jump[b - 1][i]];
    while (q--) {
        int l, r, answer = 0; cin >> l >> r;
        for (int b = levels - 1; b >= 0; --b)
            if (jump[b][l] <= r + 1) { answer += 1 << b; l = jump[b][l]; }
        cout << answer << '\n';
    }
}
