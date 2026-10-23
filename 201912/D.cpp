#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using i64 = long long;
struct Block {
    int parent, id, length;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    i64 delay;
    int k;
    cin >> delay >> k;
    vector<vector<int>> distance(n, vector<int>(n, -1));
    for (int start = 0; start < n; ++start) {
        vector<int> queue{start};
        distance[start][start] = 0;
        for (size_t head = 0; head < queue.size(); ++head)
            for (int v : graph[queue[head]])
                if (distance[start][v] < 0) {
                    distance[start][v] = distance[start][queue[head]] + 1;
                    queue.push_back(v);
                }
    }
    vector<Block> blocks{{-1, 0, 1}};
    vector<int> current(n);
    vector<map<i64, int>> future(n);
    auto better = [&](int a, int b) {
        return blocks[a].length != blocks[b].length ? blocks[a].length > blocks[b].length
                                                    : blocks[a].id < blocks[b].id;
    };
    auto advance = [&](int u, i64 time) {
        auto end = future[u].upper_bound(time);
        if (end != future[u].begin())
            current[u] = prev(end)->second;
        future[u].erase(future[u].begin(), end);
    };
    auto schedule = [&](int u, i64 time, int chain) {
        auto it = future[u].lower_bound(time);
        int previous = it == future[u].begin() ? current[u] : prev(it)->second;
        if (!better(chain, previous))
            return;
        if (it != future[u].end() && it->first == time && !better(chain, it->second))
            return;
        while (it != future[u].end() && !better(it->second, chain))
            it = future[u].erase(it);
        future[u][time] = chain;
    };
    string line;
    getline(cin, line);
    for (int i = 0; i < k; ++i) {
        getline(cin, line);
        istringstream input(line);
        int u, id;
        i64 time;
        input >> u >> time;
        --u;
        advance(u, time);
        if (input >> id) {
            int index = blocks.size();
            blocks.push_back({current[u], id, blocks[current[u]].length + 1});
            current[u] = index;
            auto &events = future[u];
            auto it = events.begin();
            while (it != events.end() && !better(it->second, index))
                it = events.erase(it);
            for (int v = 0; v < n; ++v)
                if (v != u && distance[u][v] >= 0)
                    schedule(v, time + delay * distance[u][v], index);
        } else {
            vector<int> answer;
            for (int b = current[u]; b != -1; b = blocks[b].parent)
                answer.push_back(blocks[b].id);
            reverse(answer.begin(), answer.end());
            cout << answer.size();
            for (int x : answer)
                cout << ' ' << x;
            cout << '\n';
        }
    }
}
