#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Process {
    char kind;
    int start, patience = 0, task = 0, failures = 0, remaining = 0;
    int state = 0; // 0: not started, 1: waiting, 2: running, 3: finished
    bool released = false;
    vector<int> resource, length;
    long long income = 0;
    int duration = -1;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<Process> p(n);
    int horizon = 1;
    for (auto& x : p) {
        int tasks;
        cin >> x.kind >> x.start;
        if (x.kind != 'X') cin >> x.patience;
        cin >> tasks;
        horizon = max({horizon, x.start, x.patience + 1});
        for (int j = 0; j < tasks; ++j) {
            int r, t; cin >> r >> t;
            x.resource.push_back(r - 1); x.length.push_back(t);
            horizon = max(horizon, t);
        }
    }
    vector<int> owner(m, -1);
    int quiet = 0, completed = 0;
    for (int time = 1; completed < n; ++time) {
        bool event = false;
        for (auto& x : p) if (x.state == 0 && x.start == time) {
            x.state = 1; event = true;
        }
        vector<vector<int>> normal(m), forced(m);
        for (int i = 0; i < n; ++i) if (p[i].state == 1) {
            auto& x = p[i];
            int resource = x.resource[x.task];
            if (x.kind == 'C' && x.failures >= x.patience) forced[resource].push_back(i);
            else normal[resource].push_back(i);
        }
        vector<bool> succeeded(n), releaseAtEnd(n);
        for (int r = 0; r < m; ++r) {
            if (!forced[r].empty()) {
                // All forced applicants run, but only the largest id owns r.
                owner[r] = *max_element(forced[r].begin(), forced[r].end());
                for (int i : forced[r]) succeeded[i] = true;
            } else if (owner[r] == -1 && !normal[r].empty()) {
                int i = *min_element(normal[r].begin(), normal[r].end());
                owner[r] = i; succeeded[i] = true;
            }
        }
        for (int i = 0; i < n; ++i) if (p[i].state == 1) {
            auto& x = p[i];
            bool run = succeeded[i];
            if (!run) {
                ++x.failures;
                if (x.kind == 'A' && !x.released && x.failures == x.patience) {
                    releaseAtEnd[i] = true; x.released = true; event = true;
                }
                if (x.kind == 'B' && x.failures == x.patience) run = true;
            }
            if (run) {
                x.state = 2; x.remaining = x.length[x.task]; event = true;
            }
        }
        // Ownership has settled for this segment. A stolen resource no longer
        // contributes to its old holder's income, even if that holder is running.
        vector<int> held(n);
        for (int id : owner) if (id != -1) ++held[id];
        for (int i = 0; i < n; ++i) if (p[i].state == 2) {
            auto& x = p[i];
            x.income += held[i];
            if (--x.remaining == 0) {
                event = true;
                if (++x.task == int(x.resource.size())) {
                    x.state = 3; x.duration = time - x.start + 1;
                    releaseAtEnd[i] = true; ++completed;
                } else {
                    x.state = 1; x.failures = 0; x.released = false;
                }
            }
        }
        for (int& id : owner) if (id != -1 && releaseAtEnd[id]) id = -1;
        quiet = event ? 0 : quiet + 1;
        // Every future start / running task / patience timer must trigger within
        // horizon segments. A longer silent interval means permanent waiting.
        if (quiet > horizon) break;
    }
    for (const auto& x : p) cout << x.income << ' ' << x.duration << '\n';
}
