#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<int, 4>> jobs(n);
    int sum = 0, serial = 0;
    for (auto &job : jobs) {
        for (int &x : job)
            cin >> x;
        sum += job[0];
        serial += min(job[1], job[3]);
    }
    vector<bool> possible(sum + 1);
    possible[0] = true;
    for (auto job : jobs)
        for (int s = sum; s >= job[0]; --s)
            possible[s] = possible[s] || possible[s - job[0]];
    int bound = serial;
    for (int s = 0; s <= sum; ++s)
        if (possible[s])
            bound = min(bound, max(s, sum - s));
    int base = bound, volume = base * base * base;
    const unsigned short INF = 1000;
    vector<unsigned short> dp(volume, INF), next(volume, INF);
    vector<int> active{0}, following;
    dp[0] = 0;
    for (auto job : jobs) {
        int a = job[0], c = job[2], both = min(job[1], job[3]);
        following.clear();
        auto put = [&](int x, int y, int z, int cost) {
            if (cost + max({x, y, z}) >= bound)
                return;
            if (x > y)
                swap(x, y);
            int id = (x * base + y) * base + z;
            if (next[id] == INF)
                following.push_back(id);
            next[id] = min<int>(next[id], cost);
        };
        for (int id : active) {
            int z = id % base, y = id / base % base, x = id / base / base, cost = dp[id];
            put(x + a, y, z, cost);
            put(x, y + a, z, cost);
            if (c < a) {
                put(x + c, y, z + c, cost);
                put(x, y + c, z + c, cost);
            }
            if (both < a)
                put(x, y, z, cost + both);
        }
        for (int id : active)
            dp[id] = INF;
        dp.swap(next);
        active.swap(following);
    }
    int answer = bound;
    for (int id : active)
        answer = min(answer, int(dp[id]) + max({id % base, id / base % base, id / base / base}));
    cout << answer << '\n';
}
