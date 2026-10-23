#include <deque>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
struct Node {
    int left = -1, right = -1;
    char symbol = 0;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s, capacity;
    cin >> s >> capacity;
    vector<pair<string, string>> fixed(s);
    for (auto &[key, value] : fixed)
        cin >> key >> value;
    string encoding;
    cin >> encoding;
    vector<Node> tree;
    int position = 0;
    function<int()> parse = [&]() {
        int u = tree.size();
        tree.push_back({});
        char type = encoding[position++];
        if (type == '1')
            tree[u].symbol = encoding[position++];
        else {
            int left = parse(), right = parse();
            tree[u].left = left;
            tree[u].right = right;
        }
        return u;
    };
    int root = parse();
    auto hex = [](char c) { return c <= '9' ? c - '0' : c - 'a' + 10; };
    auto decode = [&](const string &input) {
        if (input[0] != 'H')
            return input;
        if (input.size() > 1 && input[1] == 'H')
            return input.substr(1);
        int bytes = (input.size() - 1) / 2,
            padding = hex(input[input.size() - 2]) * 16 + hex(input.back());
        int bits = (bytes - 1) * 8 - padding;
        string result;
        int u = root;
        for (int i = 0; i < bits; ++i) {
            int bit = (hex(input[1 + i / 4]) >> (3 - i % 4)) & 1;
            u = bit ? tree[u].right : tree[u].left;
            if (tree[u].symbol) {
                result += tree[u].symbol;
                u = root;
            }
        }
        return result;
    };
    deque<pair<string, string>> dynamic;
    auto lookup = [&](int index) { return index <= s ? fixed[index - 1] : dynamic[index - s - 1]; };
    int n;
    cin >> n;
    while (n--) {
        int type, index;
        cin >> type >> index;
        pair<string, string> header;
        if (type == 1)
            header = lookup(index);
        else {
            string value;
            if (index == 0) {
                string key;
                cin >> key;
                header.first = decode(key);
            } else
                header.first = lookup(index).first;
            cin >> value;
            header.second = decode(value);
        }
        cout << header.first << ": " << header.second << '\n';
        if (type == 2) {
            dynamic.push_front(header);
            if (int(dynamic.size()) > capacity)
                dynamic.pop_back();
        }
    }
}
