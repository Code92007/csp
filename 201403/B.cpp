#include <iostream>
#include <vector>
using namespace std;
struct Window {
    int x1, y1, x2, y2, id;
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<Window> w(n);
    for (int i = 0; i < n; i++) {
        auto &v = w[i];
        cin >> v.x1 >> v.y1 >> v.x2 >> v.y2;
        v.id = i + 1;
    }
    while (m--) {
        int x, y, found = -1;
        cin >> x >> y;
        for (int i = n - 1; i >= 0; i--) {
            auto v = w[i];
            if (v.x1 <= x && x <= v.x2 && v.y1 <= y && y <= v.y2) {
                found = i;
                break;
            }
        }
        if (found < 0)
            cout << "IGNORED\n";
        else {
            auto v = w[found];
            cout << v.id << '\n';
            w.erase(w.begin() + found);
            w.push_back(v);
        }
    }
}
