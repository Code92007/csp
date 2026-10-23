#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> h(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    vector<int> stack{0};
    long long answer = 0;
    for (int i = 1; i <= n + 1; i++) {
        while (stack.size() > 1 && h[stack.back()] >= h[i]) {
            int top = stack.back();
            stack.pop_back();
            answer = max(answer, h[top] * (i - stack.back() - 1));
        }
        stack.push_back(i);
    }
    cout << answer << '\n';
}
