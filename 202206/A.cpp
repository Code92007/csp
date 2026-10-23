#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long double> a(n);
    long double mean = 0;
    for (auto &x : a) {
        cin >> x;
        mean += x;
    }
    mean /= n;
    long double variance = 0;
    for (auto x : a)
        variance += (x - mean) * (x - mean);
    variance /= n;
    long double sd = sqrtl(variance);
    cout << fixed << setprecision(10);
    for (auto x : a)
        cout << (x - mean) / sd << '\n';
}
