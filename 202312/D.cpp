#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
constexpr long long MOD = 998244353;
struct Matrix {
    array<long long, 4> a{1, 0, 0, 1};
};
Matrix operator*(const Matrix &x, const Matrix &y) {
    Matrix z;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            z.a[i * 2 + j] = (x.a[i * 2] * y.a[j] + x.a[i * 2 + 1] * y.a[2 + j]) % MOD;
    return z;
}
struct Command {
    int type;
    Matrix value;
};
struct Block {
    int removed = 0;
    vector<Matrix> front, back;
};
vector<Command> commands;
Block summarize(int l, int r) {
    Block result;
    vector<int> live;
    for (int i = l; i <= r; ++i) {
        if (commands[i].type != 3)
            live.push_back(i);
        else if (live.empty())
            ++result.removed;
        else
            live.pop_back();
    }
    result.front.push_back({});
    result.back.push_back({});
    for (int i : live) {
        auto &c = commands[i];
        result.front.push_back(c.type == 1 ? c.value * result.front.back() : result.front.back());
        result.back.push_back(c.type == 2 ? result.back.back() * c.value : result.back.back());
    }
    return result;
}
void read(Command &c) {
    cin >> c.type;
    if (c.type != 3)
        for (auto &x : c.value.a)
            cin >> x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    commands.resize(n);
    for (auto &c : commands)
        read(c);
    int width = max(1, int(sqrt(n))), count = (n + width - 1) / width;
    vector<Block> blocks(count);
    auto rebuild = [&](int b) {
        blocks[b] = summarize(b * width, min(n - 1, (b + 1) * width - 1));
    };
    for (int b = 0; b < count; ++b)
        rebuild(b);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i;
            cin >> i;
            --i;
            read(commands[i]);
            rebuild(i / width);
            continue;
        }
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        vector<pair<const Block *, int>> stack;
        auto append = [&](const Block &b) {
            int remove = b.removed;
            while (remove && !stack.empty()) {
                int used = min(remove, stack.back().second);
                remove -= used;
                stack.back().second -= used;
                if (stack.back().second == 0)
                    stack.pop_back();
            }
            int size = int(b.front.size()) - 1;
            if (size)
                stack.push_back({&b, size});
        };
        Block left, right;
        if (l / width == r / width) {
            left = summarize(l, r);
            append(left);
        } else {
            left = summarize(l, (l / width + 1) * width - 1);
            right = summarize(r / width * width, r);
            append(left);
            for (int b = l / width + 1; b < r / width; ++b)
                append(blocks[b]);
            append(right);
        }
        Matrix front, back;
        for (auto [block, size] : stack) {
            front = block->front[size] * front;
            back = back * block->back[size];
        }
        Matrix answer = front * back;
        for (int i = 0; i < 4; ++i)
            cout << answer.a[i] << (i == 3 ? '\n' : ' ');
    }
}
