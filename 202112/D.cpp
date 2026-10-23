#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
constexpr int NONE = numeric_limits<int>::max();
struct Info {
    int low = 0, high = 0, min_positive = NONE, max_positive = 0;
};
Info combine(Info a, Info b) {
    return {min(a.low, b.low), max(a.high, b.high), min(a.min_positive, b.min_positive),
            max(a.max_positive, b.max_positive)};
}
struct Node {
    Info info;
    int owner_tag = NONE, value = 0;
    bool value_tag = false;
};
struct Operation {
    int type, id = 0, l, r, value = 0;
};
vector<Node> tree;
void set_owner(int u, int id) {
    tree[u].info = {id, id, id > 0 ? id : NONE, id > 0 ? id : 0};
    tree[u].owner_tag = id;
}
void set_value(int u, int value) {
    tree[u].value = value;
    tree[u].value_tag = true;
}
void push(int u) {
    if (tree[u].owner_tag != NONE) {
        set_owner(u * 2, tree[u].owner_tag);
        set_owner(u * 2 + 1, tree[u].owner_tag);
        tree[u].owner_tag = NONE;
    }
    if (tree[u].value_tag) {
        set_value(u * 2, tree[u].value);
        set_value(u * 2 + 1, tree[u].value);
        tree[u].value_tag = false;
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
    return combine(query(u * 2, l, mid, a, b), query(u * 2 + 1, mid + 1, r, a, b));
}
int first_foreign(int u, int l, int r, int a, int b, int id) {
    const auto &s = tree[u].info;
    if (r < a || l > b || s.max_positive == 0 || (s.min_positive == id && s.max_positive == id))
        return -1;
    if (l == r)
        return l;
    push(u);
    int mid = (l + r) / 2;
    int left = first_foreign(u * 2, l, mid, a, b, id);
    return left != -1 ? left : first_foreign(u * 2 + 1, mid + 1, r, a, b, id);
}
void update(int u, int l, int r, int a, int b, int id, bool write, int value) {
    if (a <= l && r <= b) {
        set_owner(u, id);
        if (write)
            set_value(u, value);
        return;
    }
    push(u);
    int mid = (l + r) / 2;
    if (a <= mid)
        update(u * 2, l, mid, a, b, id, write, value);
    if (b > mid)
        update(u * 2 + 1, mid + 1, r, a, b, id, write, value);
    tree[u].info = combine(tree[u * 2].info, tree[u * 2 + 1].info);
}
pair<int, int> read(int u, int l, int r, int position) {
    if (l == r) {
        int id = tree[u].info.low;
        return id > 0 ? pair<int, int>{id, tree[u].value} : pair<int, int>{0, 0};
    }
    push(u);
    int mid = (l + r) / 2;
    return position <= mid ? read(u * 2, l, mid, position) : read(u * 2 + 1, mid + 1, r, position);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int programs, disk, k;
    cin >> programs >> disk >> k;
    vector<Operation> ops(k);
    vector<int> coordinates{1, disk + 1};
    for (auto &op : ops) {
        cin >> op.type;
        if (op.type == 3) {
            cin >> op.l;
            op.r = op.l;
        } else {
            cin >> op.id >> op.l >> op.r;
            if (op.type == 0)
                cin >> op.value;
        }
        coordinates.push_back(op.l);
        coordinates.push_back(op.r + 1);
    }
    sort(coordinates.begin(), coordinates.end());
    coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());
    int n = int(coordinates.size()) - 1;
    tree.resize(4 * n + 4);
    for (auto op : ops) {
        int l = lower_bound(coordinates.begin(), coordinates.end(), op.l) - coordinates.begin();
        int r = int(lower_bound(coordinates.begin(), coordinates.end(), op.r + 1) -
                    coordinates.begin()) -
                1;
        if (op.type == 3) {
            auto [owner, value] = read(1, 0, n - 1, l);
            cout << owner << ' ' << value << '\n';
            continue;
        }
        if (op.type == 0) {
            int blocked = first_foreign(1, 0, n - 1, l, r, op.id),
                end = blocked == -1 ? r : blocked - 1;
            if (end < l)
                cout << -1 << '\n';
            else {
                update(1, 0, n - 1, l, end, op.id, true, op.value);
                cout << coordinates[end + 1] - 1 << '\n';
            }
        } else {
            Info s = query(1, 0, n - 1, l, r);
            int required = op.type == 1 ? op.id : -op.id;
            bool ok = s.low == required && s.high == required;
            cout << (ok ? "OK" : "FAIL") << '\n';
            if (ok)
                update(1, 0, n - 1, l, r, -required, false, 0);
        }
    }
}
