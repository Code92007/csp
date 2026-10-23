#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;
constexpr int INF = 1000000000;
struct Info {
    int low = 0, high = 0, positive = INF;
};
Info merge(Info a, Info b) {
    return {min(a.low, b.low), max(a.high, b.high), min(a.positive, b.positive)};
}
struct Node {
    Info info;
    int lazy = -1;
};
struct Operation {
    int type, id = 0;
    string left, right;
};
string address() {
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(), ':'), s.end());
    return '0' + s;
}
string successor(string s) {
    const string digits = "0123456789abcdef";
    for (int i = int(s.size()) - 1; i >= 0; --i) {
        if (s[i] == 'f')
            s[i] = '0';
        else {
            s[i] = digits[digits.find(s[i]) + 1];
            break;
        }
    }
    return s;
}
vector<Node> tree;
void assign(int u, int value) {
    tree[u].info = {value, value, value ? value : INF};
    tree[u].lazy = value;
}
void push(int u) {
    if (tree[u].lazy != -1) {
        assign(u * 2, tree[u].lazy);
        assign(u * 2 + 1, tree[u].lazy);
        tree[u].lazy = -1;
    }
}
Info query(int u, int l, int r, int a, int b) {
    if (a <= l && r <= b)
        return tree[u].info;
    push(u);
    int mid = (l + r) / 2;
    if (b <= mid)
        return query(u * 2, l, mid, a, b);
    if (a > mid)
        return query(u * 2 + 1, mid + 1, r, a, b);
    return merge(query(u * 2, l, mid, a, b), query(u * 2 + 1, mid + 1, r, a, b));
}
void update(int u, int l, int r, int a, int b, int value) {
    if (a <= l && r <= b) {
        assign(u, value);
        return;
    }
    push(u);
    int mid = (l + r) / 2;
    if (a <= mid)
        update(u * 2, l, mid, a, b, value);
    if (b > mid)
        update(u * 2 + 1, mid + 1, r, a, b, value);
    tree[u].info = merge(tree[u * 2].info, tree[u * 2 + 1].info);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int bits, q;
    cin >> bits >> q;
    vector<Operation> ops(q);
    vector<string> coordinates;
    for (auto &op : ops) {
        cin >> op.type;
        if (op.type == 1)
            cin >> op.id;
        op.left = address();
        op.right = successor(op.type == 2 ? op.left : address());
        coordinates.push_back(op.left);
        coordinates.push_back(op.right);
    }
    sort(coordinates.begin(), coordinates.end());
    coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());
    int n = int(coordinates.size()) - 1;
    tree.resize(4 * n + 4);
    for (auto &op : ops) {
        int l = lower_bound(coordinates.begin(), coordinates.end(), op.left) - coordinates.begin();
        int r = int(lower_bound(coordinates.begin(), coordinates.end(), op.right) -
                    coordinates.begin()) -
                1;
        Info value = query(1, 0, n - 1, l, r);
        if (op.type == 1) {
            bool possible = value.low == 0 &&
                            (value.high == 0 || (value.high == op.id && value.positive == op.id));
            cout << (possible ? "YES" : "NO") << '\n';
            if (possible)
                update(1, 0, n - 1, l, r, op.id);
        } else
            cout << (value.low == value.high ? value.low : 0) << '\n';
    }
}
