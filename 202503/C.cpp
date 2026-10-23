#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
constexpr long long MOD = 1000000007;
struct Operand {
    bool variable;
    int value;
};
struct Variable {
    bool indirect = false;
    long long value = 0;
    vector<Operand> expression;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    unordered_map<string, int> ids;
    vector<Variable> vars(1001);
    vector<int> stamp(1001, -1);
    vector<long long> memo(1001);
    int epoch = 0;
    auto id = [&](const string &name) {
        auto it = ids.find(name);
        if (it != ids.end())
            return it->second;
        int index = ids.size();
        ids[name] = index;
        return index;
    };
    function<long long(int)> evaluate = [&](int u) {
        if (stamp[u] == epoch)
            return memo[u];
        long long value = vars[u].value;
        if (vars[u].indirect) {
            value = 0;
            for (auto operand : vars[u].expression)
                value =
                    (value + (operand.variable ? evaluate(operand.value) : operand.value)) % MOD;
        }
        stamp[u] = epoch;
        return memo[u] = value;
    };
    while (n--) {
        ++epoch;
        getline(cin, line);
        istringstream input(line);
        int op;
        string name;
        input >> op >> name;
        int target = id(name);
        if (op == 3) {
            cout << evaluate(target) << '\n';
            continue;
        }
        vector<Operand> expr;
        string token;
        while (input >> token) {
            if (token[0] == '$')
                expr.push_back({true, id(token.substr(1))});
            else
                expr.push_back({false, int(token.size())});
        }
        if (op == 1) {
            long long value = 0;
            for (auto operand : expr)
                value =
                    (value + (operand.variable ? evaluate(operand.value) : operand.value)) % MOD;
            vars[target].indirect = false;
            vars[target].value = value;
            vars[target].expression.clear();
        } else {
            vars[target].indirect = true;
            vars[target].expression = std::move(expr);
        }
    }
}
