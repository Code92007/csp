#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const ll NEG = -(1LL << 60);
using Matrix = vector<vector<ll>>;
Matrix multiply(const Matrix &a, const Matrix &b) {
    int n = a.size();
    Matrix c(n, vector<ll>(n, NEG));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            if (a[i][k] != NEG)
                for (int j = 0; j < n; ++j)
                    if (b[k][j] != NEG)
                        c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
    return c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll length;
    cin >> n >> length;
    struct Node {
        array<int, 26> next{};
        int fail = 0, reward = 0;
    };
    vector<Node> trie(1);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int u = 0;
        for (char c : s) {
            int k = c - 'a';
            if (!trie[u].next[k]) {
                trie[u].next[k] = trie.size();
                trie.emplace_back();
            }
            u = trie[u].next[k];
        }
        ++trie[u].reward;
    }
    queue<int> q;
    for (int v : trie[0].next)
        if (v)
            q.push(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        trie[u].reward += trie[trie[u].fail].reward;
        for (int c = 0; c < 26; ++c) {
            int v = trie[u].next[c];
            if (v) {
                trie[v].fail = trie[trie[u].fail].next[c];
                q.push(v);
            } else
                trie[u].next[c] = trie[trie[u].fail].next[c];
        }
    }
    int s = trie.size();
    Matrix a(s, vector<ll>(s, NEG));
    for (int u = 0; u < s; ++u)
        for (int v : trie[u].next)
            a[u][v] = trie[v].reward;
    vector<ll> dp(s, NEG);
    dp[0] = 0;
    while (length) {
        if (length & 1) {
            vector<ll> next(s, NEG);
            for (int u = 0; u < s; ++u)
                if (dp[u] != NEG)
                    for (int v = 0; v < s; ++v)
                        if (a[u][v] != NEG)
                            next[v] = max(next[v], dp[u] + a[u][v]);
            dp.swap(next);
        }
        length >>= 1;
        if (length)
            a = multiply(a, a);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
