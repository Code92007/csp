#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
using Real = long double;
struct Matrix {
    Real a[3][3]{};
    static Matrix identity() {
        Matrix m;
        for (int i = 0; i < 3; ++i)
            m.a[i][i] = 1;
        return m;
    }
};
Matrix operator*(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < 3; ++i)
        for (int k = 0; k < 3; ++k)
            for (int j = 0; j < 3; ++j)
                c.a[i][j] += a.a[i][k] * b.a[k][j];
    return c;
}
struct Moments {
    Real count = 0, x = 0, y = 0, xx = 0, xy = 0, yy = 0;
};
Moments operator+(Moments a, Moments b) {
    if (!a.count)
        return b;
    if (!b.count)
        return a;
    Real count = a.count + b.count, dx = b.x - a.x, dy = b.y - a.y,
         factor = a.count * b.count / count;
    return {count,
            a.x + dx * b.count / count,
            a.y + dy * b.count / count,
            a.xx + b.xx + factor * dx * dx,
            a.xy + b.xy + factor * dx * dy,
            a.yy + b.yy + factor * dy * dy};
}
Moments transform(const Moments &s, const Matrix &t) {
    Real a = t.a[0][0], b = t.a[0][1], c = t.a[1][0], d = t.a[1][1];
    return {s.count,
            a * s.x + b * s.y + t.a[0][2],
            c * s.x + d * s.y + t.a[1][2],
            a * a * s.xx + 2 * a * b * s.xy + b * b * s.yy,
            a * c * s.xx + (a * d + b * c) * s.xy + b * d * s.yy,
            c * c * s.xx + 2 * c * d * s.xy + d * d * s.yy};
}
struct Tree {
    vector<Moments> moment;
    vector<Matrix> lazy;
    vector<bool> pending;
    vector<array<Real, 2>> point;
    explicit Tree(int n) : moment(4 * n + 4), lazy(4 * n + 4), pending(4 * n + 4), point(n + 1) {}
    void build(int u, int l, int r) {
        lazy[u] = Matrix::identity();
        if (l == r) {
            moment[u] = {1, point[l][0], point[l][1], 0, 0, 0};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * u, l, mid);
        build(2 * u + 1, mid + 1, r);
        moment[u] = moment[2 * u] + moment[2 * u + 1];
    }
    void apply(int u, const Matrix &t) {
        moment[u] = transform(moment[u], t);
        lazy[u] = t * lazy[u];
        pending[u] = true;
    }
    void push(int u) {
        if (pending[u]) {
            apply(2 * u, lazy[u]);
            apply(2 * u + 1, lazy[u]);
            lazy[u] = Matrix::identity();
            pending[u] = false;
        }
    }
    void update(int u, int l, int r, int a, int b, const Matrix &t) {
        if (a <= l && r <= b) {
            apply(u, t);
            return;
        }
        push(u);
        int mid = (l + r) / 2;
        if (a <= mid)
            update(2 * u, l, mid, a, b, t);
        if (b > mid)
            update(2 * u + 1, mid + 1, r, a, b, t);
        moment[u] = moment[2 * u] + moment[2 * u + 1];
    }
    Moments query(int u, int l, int r, int a, int b) {
        if (a <= l && r <= b)
            return moment[u];
        push(u);
        int mid = (l + r) / 2;
        Moments result;
        if (a <= mid)
            result = result + query(2 * u, l, mid, a, b);
        if (b > mid)
            result = result + query(2 * u + 1, mid + 1, r, a, b);
        return result;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
    int n, q;
    cin >> n >> q;
    Tree tree(n);
    for (int i = 1; i <= n; ++i)
        cin >> tree.point[i][0] >> tree.point[i][1];
    tree.build(1, 1, n);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op >= 6) {
            auto s = tree.query(1, 1, n, l, r);
            if (op == 6)
                cout << s.x << ' ' << s.y << '\n';
            else {
                Real a, b;
                cin >> a >> b;
                Real dx = s.x - a, dy = s.y - b;
                Real answer = s.xx + s.yy + s.count * (dx * dx + dy * dy);
                cout << max(Real(0), answer) << '\n';
            }
            continue;
        }
        Matrix t = Matrix::identity();
        Real a, b;
        if (op == 1) {
            cin >> a >> b;
            t.a[0][2] = a;
            t.a[1][2] = b;
        } else if (op == 2 || op == 3) {
            Real x;
            cin >> a >> b >> x;
            if (op == 2) {
                Real c = cosl(x), s = sinl(x);
                t.a[0][0] = t.a[1][1] = c;
                t.a[0][1] = -s;
                t.a[1][0] = s;
            } else
                t.a[0][0] = t.a[1][1] = x;
            t.a[0][2] = a - t.a[0][0] * a - t.a[0][1] * b;
            t.a[1][2] = b - t.a[1][0] * a - t.a[1][1] * b;
        } else {
            Real angle, y0;
            cin >> angle >> y0;
            Real c = cosl(angle), s = sinl(angle), factor = op == 4 ? 2 : 1,
                 subtract = op == 4 ? 1 : 0;
            t.a[0][0] = factor * c * c - subtract;
            t.a[0][1] = t.a[1][0] = factor * c * s;
            t.a[1][1] = factor * s * s - subtract;
            t.a[0][2] = -t.a[0][1] * y0;
            t.a[1][2] = y0 - t.a[1][1] * y0;
        }
        tree.update(1, 1, n, l, r, t);
    }
}
