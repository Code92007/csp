#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <vector>
using namespace std;

constexpr uint32_t MOD = 998244353;
struct Matrix {
    uint32_t a = 1, b = 0, c = 0, d = 1;
};
inline Matrix multiply(const Matrix &x, const Matrix &y) {
    return {
        uint32_t((uint64_t(x.a) * y.a + uint64_t(x.b) * y.c) % MOD),
        uint32_t((uint64_t(x.a) * y.b + uint64_t(x.b) * y.d) % MOD),
        uint32_t((uint64_t(x.c) * y.a + uint64_t(x.d) * y.c) % MOD),
        uint32_t((uint64_t(x.c) * y.b + uint64_t(x.d) * y.d) % MOD)
    };
}
struct Product {
    Matrix front, back;
};
// Execute x before y: later front insertions precede all earlier ones.
inline Product join(const Product &x, const Product &y) {
    return {multiply(y.front, x.front), multiply(x.back, y.back)};
}

class FastIO {
    static constexpr int SIZE = 1 << 16;
    char input[SIZE], output[SIZE];
    int pos = 0, length = 0, used = 0;
    int get() {
        if (pos == length) {
            length = int(fread(input, 1, SIZE, stdin));
            pos = 0;
            if (!length) return EOF;
        }
        return input[pos++];
    }
public:
    ~FastIO() { flush(); }
    int read() {
        int ch = get(), value = 0;
        while (ch <= ' ' && ch != EOF) ch = get();
        while (ch >= '0' && ch <= '9') {
            value = value * 10 + ch - '0';
            ch = get();
        }
        return value;
    }
    void flush() {
        fwrite(output, 1, used, stdout);
        used = 0;
    }
    void write(uint32_t value, char end) {
        if (used + 12 >= SIZE) flush();
        char digits[10];
        int count = 0;
        do {
            digits[count++] = char('0' + value % 10);
            value /= 10;
        } while (value);
        while (count) output[used++] = digits[--count];
        output[used++] = end;
    }
};

struct Node {
    int removed = 0, size = 0, leftSize = 0;
    Product all, leftPart;
};

class SegmentTree {
    int base = 1;
    vector<Node> nodes;

    // First count insertions of this node's reduced chronological sequence.
    Product prefix(int u, int count) const {
        const Node &node = nodes[u];
        if (count == node.size) return node.all;
        if (!count) return {};
        if (count <= node.leftSize) return prefix(u * 2, count);
        return join(node.leftPart, prefix(u * 2 + 1, count - node.leftSize));
    }

    void pull(int u) {
        Node &node = nodes[u];
        const Node &left = nodes[u * 2], &right = nodes[u * 2 + 1];
        node.leftSize = max(0, left.size - right.removed);
        node.size = node.leftSize + right.size;
        node.removed = left.removed + max(0, right.removed - left.size);
        node.leftPart = prefix(u * 2, node.leftSize);
        if (!node.leftSize) node.all = right.all;
        else if (!right.size) node.all = node.leftPart;
        else node.all = join(node.leftPart, right.all);
    }

    void setLeaf(int u, int type, const Matrix &value) {
        Node &node = nodes[u];
        node.removed = type == 3;
        node.size = type != 3;
        node.all = {};
        if (type == 1) node.all.front = value;
        if (type == 2) node.all.back = value;
    }

public:
    explicit SegmentTree(int n) {
        while (base < n) base *= 2;
        nodes.resize(base * 2);
    }
    void initialize(int i, int type, const Matrix &value) {
        setLeaf(base + i, type, value);
    }
    void build() {
        for (int u = base - 1; u; --u) pull(u);
    }
    void update(int i, int type, const Matrix &value) {
        int u = base + i;
        setLeaf(u, type, value);
        while ((u /= 2)) pull(u);
    }
    Matrix query(int l, int r) const {
        // Collect the disjoint covering nodes in chronological order.
        int leftNodes[32], rightNodes[32], nl = 0, nr = 0;
        for (l += base, r += base + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) leftNodes[nl++] = l++;
            if (r & 1) rightNodes[nr++] = --r;
        }
        int removed = 0;
        Product answer;
        bool nonempty = false;
        auto consume = [&](int u) {
            const Node &node = nodes[u];
            if (node.size <= removed) {
                removed += node.removed - node.size;
            } else {
                Product part = prefix(u, node.size - removed);
                answer = nonempty ? join(part, answer) : part;
                nonempty = true;
                removed = node.removed;
            }
        };
        // Scan backwards: later deletions remove a suffix of earlier survivors.
        for (int i = 0; i < nr; ++i) consume(rightNodes[i]);
        for (int i = nl - 1; i >= 0; --i) consume(leftNodes[i]);
        return multiply(answer.front, answer.back);
    }
};

int main() {
    FastIO io;
    int n = io.read(), m = io.read();
    SegmentTree tree(n);
    auto readMatrix = [&](int type) {
        Matrix value;
        if (type != 3) {
            value.a = io.read(); value.b = io.read();
            value.c = io.read(); value.d = io.read();
        }
        return value;
    };
    for (int i = 0; i < n; ++i) {
        int type = io.read();
        tree.initialize(i, type, readMatrix(type));
    }
    tree.build();
    while (m--) {
        int op = io.read();
        if (op == 1) {
            int i = io.read() - 1, type = io.read();
            tree.update(i, type, readMatrix(type));
        } else {
            int l = io.read() - 1, r = io.read() - 1;
            Matrix answer = tree.query(l, r);
            io.write(answer.a, ' '); io.write(answer.b, ' ');
            io.write(answer.c, ' '); io.write(answer.d, '\n');
        }
    }
}
