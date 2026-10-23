#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, s;
    string text;
    cin >> w >> s >> text;
    vector<int> chars;
    int mode = 0;
    for (char c : text) {
        int next = (c >= 'A' && c <= 'Z') ? 0 : (c >= 'a' && c <= 'z') ? 1 : 2;
        if (mode != next) {
            if (next == 1)
                chars.push_back(27);
            else if (next == 2)
                chars.push_back(28);
            else {
                chars.push_back(28);
                if (mode == 1)
                    chars.push_back(28);
            }
            mode = next;
        }
        chars.push_back(c - (mode == 0 ? 'A' : mode == 1 ? 'a' : '0'));
    }
    if (chars.size() % 2)
        chars.push_back(29);
    vector<int> data(1, 0);
    for (size_t i = 0; i < chars.size(); i += 2)
        data.push_back(chars[i] * 30 + chars[i + 1]);
    int k = s < 0 ? 0 : 1 << (s + 1);
    while ((data.size() + k) % w)
        data.push_back(900);
    data[0] = int(data.size());
    for (int x : data)
        cout << x << '\n';
    if (!k)
        return 0;
    // 按降幂顺序存储多项式，每次乘 (x - 3^i)。
    vector<int> g(1, 1);
    int power = 1;
    for (int i = 1; i <= k; i++) {
        power = power * 3 % 929;
        vector<int> next(g.size() + 1);
        for (size_t j = 0; j < g.size(); j++) {
            next[j] = (next[j] + g[j]) % 929;
            next[j + 1] = (next[j + 1] - g[j] * power % 929 + 929) % 929;
        }
        g.swap(next);
    }
    vector<int> rem = data;
    rem.resize(data.size() + k);
    for (size_t i = 0; i < data.size(); i++) {
        int factor = rem[i];
        for (int j = 0; j <= k; j++)
            rem[i + j] = (rem[i + j] - factor * g[j] % 929 + 929) % 929;
    }
    for (size_t i = data.size(); i < rem.size(); i++)
        cout << (929 - rem[i]) % 929 << '\n';
}
