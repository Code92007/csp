#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll period;
    if (!(cin >> n >> m >> period)) return 0;
    vector<int> quantum(m), work(n);
    for (int& x : quantum) cin >> x;
    vector<vector<bool>> preferred(n, vector<bool>(m));
    vector<queue<int>> waiting(m);
    for (int i = 0; i < n; ++i) {
        int count; cin >> work[i] >> count;
        while (count--) { int cpu; cin >> cpu; preferred[i][cpu - 1] = true; }
        waiting[i % m].push(i);
    }
    vector<int> running(m, -1);
    vector<ll> ends(m), first(n, -1), answer(n);
    int completed = 0;
    for (ll now = 0; completed < n; ++now) {
        // Complete slices before applying a rotation at this timestamp.
        for (int cpu = 0; cpu < m; ++cpu) {
            int job = running[cpu];
            if (job == -1 || ends[cpu] != now) continue;
            if (work[job] == 0) {
                answer[job] = now - first[job];
                ++completed;
            } else {
                int oldQueue = (cpu + (now - 1) / period % m) % m;
                waiting[oldQueue].push(job);
            }
            running[cpu] = -1;
        }
        if (completed == n) break;
        int shift = now / period % m;
        for (int cpu = 0; cpu < m; ++cpu) {
            int queueId = (cpu + shift) % m;
            if (running[cpu] != -1 || waiting[queueId].empty()) continue;
            int job = waiting[queueId].front();
            waiting[queueId].pop();
            int speed = preferred[job][cpu] ? 2 : 1;
            int duration = min(quantum[cpu], (work[job] + speed - 1) / speed);
            if (first[job] == -1) first[job] = now;
            work[job] = max(0, work[job] - duration * speed);
            running[cpu] = job;
            ends[cpu] = now + duration;
        }
    }
    for (int i = 0; i < n; ++i) cout << answer[i] << (i + 1 == n ? '\n' : ' ');
}
