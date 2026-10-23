#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
string lower(string s) {
    for (char &c : s)
        c = tolower(static_cast<unsigned char>(c));
    return s;
}
struct Node {
    string tag, id;
    int parent;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string line;
    getline(cin, line);
    vector<Node> a(n + 1);
    vector<int> stack;
    for (int i = 1; i <= n; i++) {
        getline(cin, line);
        int d = 0;
        while (line[d] == '.')
            ++d;
        d /= 2;
        while (int(stack.size()) > d)
            stack.pop_back();
        a[i].parent = stack.empty() ? 0 : stack.back();
        istringstream in(line.substr(2 * d));
        in >> a[i].tag >> a[i].id;
        a[i].tag = lower(a[i].tag);
        stack.push_back(i);
    }
    while (m--) {
        getline(cin, line);
        istringstream in(line);
        vector<string> sel;
        string t;
        while (in >> t)
            sel.push_back(t[0] == '#' ? t : lower(t));
        auto match = [&](int u, int k) {
            return sel[k][0] == '#' ? a[u].id == sel[k] : a[u].tag == sel[k];
        };
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            int k = int(sel.size()) - 1;
            if (!match(i, k))
                continue;
            --k;
            int u = a[i].parent;
            while (k >= 0 && u) {
                if (match(u, k))
                    --k;
                u = a[u].parent;
            }
            if (k < 0)
                ans.push_back(i);
        }
        cout << ans.size();
        for (int u : ans)
            cout << ' ' << u;
        cout << '\n';
    }
}
