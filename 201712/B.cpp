#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    int count = 1;
    while (q.size() > 1) {
        int child = q.front();
        q.pop();
        if (count % k != 0 && count % 10 != k)
            q.push(child);
        ++count;
    }
    cout << q.front() << '\n';
}
