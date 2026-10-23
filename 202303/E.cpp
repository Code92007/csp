#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;
struct Range {
    int base, identity;
    bool minimum;
    vector<int> t;
    Range(int n, bool mn)
        : base(n), identity(mn ? 1000000000 : -1000000000), minimum(mn), t(2 * n, identity) {}
    int combine(int a, int b) {
        return minimum ? min(a, b) : max(a, b);
    }
    void put(int x, int v) {
        x += base;
        t[x] = combine(t[x], v);
        for (x >>= 1; x; x >>= 1)
            t[x] = combine(t[2 * x], t[2 * x + 1]);
    }
    int get(int l, int r) {
        if (l > r)
            return identity;
        int ans = identity;
        for (l += base, r += base + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ans = combine(ans, t[l++]);
            if (r & 1)
                ans = combine(ans, t[--r]);
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> intervals(m);
    for (auto &a : intervals)
        cin >> a.first >> a.second;
    function<long long(int, int, vector<pair<int, int>>)> solve =
        [&](int lo, int hi, vector<pair<int, int>> items) -> long long {
        if (lo == hi || items.empty())
            return 0;
        int mid = (lo + hi) / 2, len = hi - lo + 1;
        vector<pair<int, int>> left, right, cross;
        vector<int> furthest(len), nearest(len);
        for (int i = lo; i <= hi; ++i) {
            furthest[i - lo] = i - 1;
            nearest[i - lo] = i + 1;
        }
        for (auto [l, r] : items) {
            if (r <= mid) {
                left.push_back({l, r});
                furthest[l - lo] = max(furthest[l - lo], r);
            } else if (l > mid) {
                right.push_back({l, r});
                nearest[r - lo] = min(nearest[r - lo], l);
            } else
                cross.push_back({l, r});
        }
        vector<int> needRight(mid - lo + 1), needLeft(hi - mid);
        {
            Range reach(len, false), ends(len, true);
            for (auto [l, r] : cross)
                ends.put(l - lo, r);
            for (int L = mid; L >= lo; --L) {
                int a = furthest[L - lo];
                a = max(a, reach.get(L + 1 - lo, min(mid, a + 1) - lo));
                reach.put(L - lo, a);
                int b = ends.get(L - lo, min(mid, a + 1) - lo);
                if (a == mid)
                    b = min(b, mid + 1);
                needRight[L - lo] = b;
            }
        }
        {
            Range reach(len, true), starts(len, false);
            for (auto [l, r] : cross)
                starts.put(r - lo, l);
            for (int R = mid + 1; R <= hi; ++R) {
                int a = nearest[R - lo];
                a = min(a, reach.get(max(mid + 1, a - 1) - lo, R - 1 - lo));
                reach.put(R - lo, a);
                int b = starts.get(max(mid + 1, a - 1) - lo, R - lo);
                if (a == mid + 1)
                    b = max(b, mid);
                needLeft[R - mid - 1] = b;
            }
        }
        vector<pair<int, int>> events;
        for (int L = lo; L <= mid; ++L)
            events.push_back({needRight[L - lo], L});
        sort(events.begin(), events.end());
        vector<int> bit(mid - lo + 2);
        size_t p = 0;
        long long answer = 0;
        for (int R = mid + 1; R <= hi; ++R) {
            while (p < events.size() && events[p].first <= R) {
                int x = events[p++].second - lo + 1;
                for (; x < int(bit.size()); x += x & -x)
                    ++bit[x];
            }
            int bound = min(mid, needLeft[R - mid - 1]);
            for (int x = bound - lo + 1; x > 0; x -= x & -x)
                answer += bit[x];
        }
        // Release this level's bulky lists before recursing.
        return answer + solve(lo, mid, std::move(left)) + solve(mid + 1, hi, std::move(right));
    };
    cout << solve(1, n, std::move(intervals)) << '\n';
}
