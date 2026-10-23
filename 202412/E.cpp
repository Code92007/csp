#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> originalA(n + 2), originalB(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> originalA[i];
    for (int i = 1; i <= n; ++i)
        cin >> originalB[i];
    int q;
    cin >> q;
    vector<int> left(n + 2), right(n + 2), stack;
    stack.reserve(n);
    vector<ll> prefix(n + 2), answer(n + 2), maximum;
    maximum.reserve(n);
    while (q--) {
        auto a = originalA, b = originalB;
        int k;
        cin >> k;
        while (k--) {
            int i;
            cin >> i;
            cin >> a[i] >> b[i];
        }
        for (int i = 1; i <= n; ++i)
            prefix[i] = prefix[i - 1] + b[i];
        stack.clear();
        for (int i = 1; i <= n; ++i) {
            while (!stack.empty() && a[stack.back()] < a[i])
                stack.pop_back();
            left[i] = stack.empty() ? 0 : stack.back();
            stack.push_back(i);
        }
        stack.clear();
        for (int i = n; i >= 1; --i) {
            while (!stack.empty() && a[stack.back()] < a[i])
                stack.pop_back();
            right[i] = stack.empty() ? n + 1 : stack.back();
            stack.push_back(i);
        }
        stack.clear();
        maximum.clear();
        for (int p = 1; p < n; ++p) {
            while (!stack.empty() && stack.back() < p) {
                stack.pop_back();
                maximum.pop_back();
            }
            ll need = a[p] - (prefix[right[p] - 1] - prefix[p]);
            stack.push_back(right[p] - 1);
            maximum.push_back(max(need, maximum.empty() ? 0LL : maximum.back()));
            answer[p] = maximum.back();
        }
        stack.clear();
        maximum.clear();
        ll result = 0;
        for (int p = n - 1; p >= 1; --p) {
            while (!stack.empty() && stack.back() > p) {
                stack.pop_back();
                maximum.pop_back();
            }
            int j = p + 1;
            ll need = a[j] - (prefix[j - 1] - prefix[left[j]]);
            stack.push_back(left[j]);
            maximum.push_back(max(need, maximum.empty() ? 0LL : maximum.back()));
            result ^= max(answer[p], maximum.back());
        }
        cout << result << '\n';
    }
}
