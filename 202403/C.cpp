#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using i64 = long long;
i64 power(i64 x, i64 e, i64 mod) {
    i64 result = 1;
    while (e) {
        if (e & 1)
            result = result * x % mod;
        x = x * x % mod;
        e /= 2;
    }
    return result;
}
int rank_mod(vector<vector<i64>> a, i64 mod) {
    int rows = a.size(), columns = a[0].size(), rank = 0;
    for (int c = 0; c < columns && rank < rows; ++c) {
        int pivot = rank;
        while (pivot < rows && a[pivot][c] == 0)
            ++pivot;
        if (pivot == rows)
            continue;
        swap(a[pivot], a[rank]);
        i64 inverse = power(a[rank][c], mod - 2, mod);
        for (int j = c; j < columns; ++j)
            a[rank][j] = a[rank][j] * inverse % mod;
        for (int i = rank + 1; i < rows; ++i)
            if (a[i][c]) {
                i64 factor = a[i][c];
                for (int j = c; j < columns; ++j)
                    a[i][j] = (a[i][j] - factor * a[rank][j] % mod + mod) % mod;
            }
        ++rank;
    }
    return rank;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<i64> primes;
    for (i64 value = 1000000007; primes.size() < 12; value += 2) {
        bool prime = true;
        for (i64 d = 3; d * d <= value; d += 2)
            if (value % d == 0) {
                prime = false;
                break;
            }
        if (prime)
            primes.push_back(value);
    }
    int tests;
    cin >> tests;
    while (tests--) {
        int m;
        cin >> m;
        map<string, int> row;
        vector<vector<i64>> matrix;
        for (int c = 0; c < m; ++c) {
            string s;
            cin >> s;
            size_t i = 0;
            while (i < s.size()) {
                size_t begin = i;
                while (i < s.size() && islower(static_cast<unsigned char>(s[i])))
                    ++i;
                string element = s.substr(begin, i - begin);
                int number = 0;
                while (i < s.size() && isdigit(static_cast<unsigned char>(s[i])))
                    number = number * 10 + s[i++] - '0';
                auto it = row.find(element);
                int r;
                if (it == row.end()) {
                    r = row.size();
                    row[element] = r;
                    matrix.push_back(vector<i64>(m));
                } else
                    r = it->second;
                matrix[r][c] = number;
            }
        }
        bool dependent = true;
        if (matrix.size() >= size_t(m))
            for (i64 p : primes)
                if (rank_mod(matrix, p) == m) {
                    dependent = false;
                    break;
                }
        cout << (dependent ? 'Y' : 'N') << '\n';
    }
}
