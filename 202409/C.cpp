#include <algorithm>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct Block {
    long long start, old_count, new_count;
    vector<int> before, after;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    vector<string> text;
    unordered_map<string, int> ids;
    auto id = [&](const string &s) {
        auto it = ids.find(s);
        if (it != ids.end())
            return it->second;
        int x = text.size();
        text.push_back(s);
        ids[s] = x;
        return x;
    };
    vector<int> original(n);
    for (auto &x : original) {
        getline(cin, line);
        x = id(line);
    }
    vector<Block> blocks;
    bool valid = true;
    regex header("^@@ -([1-9][0-9]*),([1-9][0-9]*) \\+([1-9][0-9]*),([1-9][0-9]*) @@$");
    auto number = [](const string &s) {
        long long x = 0;
        for (char c : s) {
            x = x * 10 + c - '0';
            if (x > 1000000000000LL)
                return 1000000000000LL;
        }
        return x;
    };
    while (getline(cin, line)) {
        if (!line.empty() && line[0] == '#')
            continue;
        if (!line.empty() && line[0] == '@') {
            smatch match;
            if (!regex_match(line, match, header)) {
                valid = false;
                break;
            }
            Block b{number(match[1]), number(match[2]), number(match[4]), {}, {}};
            if (!blocks.empty() && b.start < blocks.back().start + blocks.back().old_count) {
                valid = false;
                break;
            }
            blocks.push_back(std::move(b));
        } else if (!blocks.empty()) {
            if (line.empty() || (line[0] != ' ' && line[0] != '+' && line[0] != '-')) {
                valid = false;
                break;
            }
            int value = id(line.substr(1));
            if (line[0] != '+')
                blocks.back().before.push_back(value);
            if (line[0] != '-')
                blocks.back().after.push_back(value);
        }
    }
    if (blocks.empty())
        valid = false;
    for (const auto &b : blocks)
        if (b.old_count != static_cast<long long>(b.before.size()) ||
            b.new_count != static_cast<long long>(b.after.size()))
            valid = false;
    vector<int> result;
    int consumed = 0;
    long long offset = 0;
    if (valid)
        for (const auto &b : blocks) {
            int length = b.before.size();
            vector<int> failure(length);
            for (int i = 1, j = 0; i < length; ++i) {
                while (j && b.before[i] != b.before[j])
                    j = failure[j - 1];
                if (b.before[i] == b.before[j])
                    ++j;
                failure[i] = j;
            }
            long long expected = b.start - 1 + offset,
                      best_delta = numeric_limits<long long>::max();
            int best = -1;
            for (int i = consumed, j = 0; i < n; ++i) {
                while (j && original[i] != b.before[j])
                    j = failure[j - 1];
                if (original[i] == b.before[j])
                    ++j;
                if (j == length) {
                    int start = i - length + 1;
                    long long delta = start - expected;
                    if (abs(delta) < length &&
                        (best == -1 || abs(delta) < abs(best_delta) ||
                         (abs(delta) == abs(best_delta) && delta < best_delta))) {
                        best = start;
                        best_delta = delta;
                    }
                    j = failure[j - 1];
                }
            }
            if (best == -1) {
                valid = false;
                break;
            }
            result.insert(result.end(), original.begin() + consumed, original.begin() + best);
            result.insert(result.end(), b.after.begin(), b.after.end());
            consumed = best + length;
            offset += best_delta;
        }
    if (!valid) {
        cout << "Patch is damaged.\n";
        return 0;
    }
    result.insert(result.end(), original.begin() + consumed, original.end());
    for (int x : result)
        cout << text[x] << '\n';
}
