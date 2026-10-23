// Exact subset DP for the n <= 10 subtask only. See README.md for its limit.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        tree[u].push_back(v); tree[v].push_back(u);
    }
    if (n > 10) {
        cerr << "This implementation only covers n <= 10.\n";
        return 2;
    }
    vector<int> star(n);
    for (int u = 0; u < n; ++u) {
        star[u] = 1 << u;
        for (int v : tree[u]) star[u] |= 1 << v;
    }
    using Sequence = vector<int>;
    vector<vector<Sequence>> dp(1 << n, vector<Sequence>(n));
    auto relax = [](Sequence& target, const Sequence& value) {
        if (target.empty() || value < target) { target = value; return true; }
        return false;
    };
    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
            if (star[u] >> v & 1) dp[star[u]][u].push_back(v + 1);
    for (int mask = 1; mask < (1 << n); ++mask) {
        // Close transitions that move the block without absorbing new numbers.
        for (int round = 0; round < n; ++round) {
            bool changed = false;
            for (int u = 0; u < n; ++u) if (!dp[mask][u].empty())
                for (int c : tree[u]) if ((star[c] | mask) == mask)
                    changed |= relax(dp[mask][c], dp[mask][u]);
            if (!changed) break;
        }
        for (int u = 0; u < n; ++u) if (!dp[mask][u].empty()) {
            vector<int> centres = tree[u]; centres.push_back(u);
            for (int c : centres) {
                int next = mask | star[c], added = star[c] & ~mask;
                if (!added) continue;
                Sequence candidate;
                const auto& old = dp[mask][u];
                for (int v = 0; v < n; ++v)
                    if ((added >> v & 1) && v + 1 < old.front()) candidate.push_back(v + 1);
                candidate.insert(candidate.end(), old.begin(), old.end());
                for (int v = 0; v < n; ++v)
                    if ((added >> v & 1) && v + 1 > old.front()) candidate.push_back(v + 1);
                relax(dp[next][c], candidate);
            }
        }
    }
    Sequence answer;
    for (const auto& seq : dp.back()) if (!seq.empty()) relax(answer, seq);
    for (int i = 0; i < n; ++i) cout << answer[i] << (i + 1 == n ? '\n' : ' ');
}
