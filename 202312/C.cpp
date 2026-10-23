#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
struct Decision {
    int question = 0, yes = -1, no = -1;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> weight(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> weight[i];
    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        children[p].push_back(i);
    }
    vector<int> tin(n + 1), tout(n + 1);
    int timer = 0;
    function<void(int)> dfs = [&](int u) {
        tin[u] = timer++;
        for (int v : children[u])
            dfs(v);
        tout[u] = timer;
    };
    dfs(1);
    vector<Decision> decisions;
    decisions.reserve(2 * n);
    function<int(const vector<int> &)> build = [&](const vector<int> &candidates) {
        int node = decisions.size();
        decisions.push_back({});
        if (candidates.size() == 1)
            return node;
        vector<long long> prefix(n + 1);
        for (int u : candidates)
            prefix[tin[u] + 1] = weight[u];
        for (int i = 1; i <= n; ++i)
            prefix[i] += prefix[i - 1];
        long long best = -1;
        int chosen = 0;
        for (int u : candidates) {
            long long difference = llabs(prefix[n] - 2 * (prefix[tout[u]] - prefix[tin[u]]));
            if (best == -1 || difference < best || (difference == best && u < chosen)) {
                best = difference;
                chosen = u;
            }
        }
        vector<int> yes, no;
        for (int u : candidates)
            (tin[chosen] <= tin[u] && tin[u] < tout[chosen] ? yes : no).push_back(u);
        decisions[node].question = chosen;
        int y = build(yes), z = build(no);
        decisions[node].yes = y;
        decisions[node].no = z;
        return node;
    };
    vector<int> all(n);
    iota(all.begin(), all.end(), 1);
    int root = build(all);
    while (m--) {
        int target;
        cin >> target;
        int u = root;
        bool first = true;
        while (decisions[u].question) {
            int question = decisions[u].question;
            if (!first)
                cout << ' ';
            first = false;
            cout << question;
            u = tin[question] <= tin[target] && tin[target] < tout[question] ? decisions[u].yes
                                                                             : decisions[u].no;
        }
        cout << '\n';
    }
}
