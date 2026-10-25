#include <algorithm>
#include <bitset>
#include <cstdint>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using Bits = bitset<2500>;

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
        int c = get(), value = 0;
        while (c <= ' ' && c != EOF) c = get();
        while (c >= '0' && c <= '9') {
            value = value * 10 + c - '0';
            c = get();
        }
        return value;
    }
    string word() {
        string result;
        int c = get();
        while (c <= ' ' && c != EOF) c = get();
        while (c > ' ') {
            result.push_back(char(c));
            c = get();
        }
        return result;
    }
    void flush() {
        fwrite(output, 1, used, stdout);
        used = 0;
    }
    void put(char c) {
        if (used == SIZE) flush();
        output[used++] = c;
    }
    void write(int value) {
        char digits[10];
        int count = 0;
        do {
            digits[count++] = char('0' + value % 10);
            value /= 10;
        } while (value);
        while (count) put(digits[--count]);
    }
};

uint64_t encode(int attribute, int value) {
    return (uint64_t(attribute) << 32) | uint32_t(value);
}
int number(const string &text, size_t &pos) {
    int value = 0;
    while (pos < text.size() && text[pos] >= '0' && text[pos] <= '9')
        value = value * 10 + text[pos++] - '0';
    return value;
}
struct Record {
    uint64_t key;
    int user;
};

class Evaluator {
    const vector<uint64_t> &keys;
    const vector<int> &attributeOf;
    const vector<Bits> &equals, &exists;
public:
    Evaluator(const vector<uint64_t> &k, const vector<int> &a,
              const vector<Bits> &e, const vector<Bits> &h)
        : keys(k), attributeOf(a), equals(e), exists(h) {}
    Bits parse(const string &text, size_t &pos) const {
        if (text[pos] == '&' || text[pos] == '|') {
            char op = text[pos++];
            ++pos; // '('
            Bits left = parse(text, pos);
            pos += 2; // ')('
            Bits right = parse(text, pos);
            ++pos; // ')'
            return op == '&' ? left & right : left | right;
        }
        int attribute = number(text, pos);
        char op = text[pos++];
        int value = number(text, pos);
        size_t index = lower_bound(keys.begin(), keys.end(), encode(attribute, value)) - keys.begin();
        if (op == ':') return equals[index];
        // A missing attribute never satisfies either assertion form.
        return exists[attributeOf[index]] & ~equals[index];
    }
};

int main() {
    FastIO io;
    int n = io.read();
    vector<pair<int, int>> dn;
    vector<Record> records;
    records.reserve(n * 500);
    for (int i = 0; i < n; ++i) {
        int id = io.read(), count = io.read();
        dn.push_back({id, i});
        while (count--) {
            int attribute = io.read(), value = io.read();
            records.push_back({encode(attribute, value), i});
        }
    }
    int m = io.read();
    vector<string> expressions(m);
    vector<uint64_t> keys;
    for (string &text : expressions) {
        text = io.word();
        for (size_t pos = 0; pos < text.size();) {
            if (text[pos] >= '0' && text[pos] <= '9') {
                int attribute = number(text, pos);
                ++pos; // ':' or '~'
                int value = number(text, pos);
                keys.push_back(encode(attribute, value));
            } else {
                ++pos;
            }
        }
    }
    sort(keys.begin(), keys.end());
    keys.erase(unique(keys.begin(), keys.end()), keys.end());
    vector<int> attributes, attributeOf;
    for (uint64_t key : keys) {
        int attribute = int(key >> 32);
        if (attributes.empty() || attributes.back() != attribute)
            attributes.push_back(attribute);
        attributeOf.push_back(int(attributes.size()) - 1);
    }
    vector<Bits> equals(keys.size()), exists(attributes.size());
    sort(records.begin(), records.end(), [](const Record &a, const Record &b) {
        return a.key < b.key;
    });
    size_t keyIndex = 0, attributeIndex = 0;
    for (const Record &record : records) {
        int attribute = int(record.key >> 32);
        while (attributeIndex < attributes.size() && attributes[attributeIndex] < attribute)
            ++attributeIndex;
        if (attributeIndex < attributes.size() && attributes[attributeIndex] == attribute)
            exists[attributeIndex].set(record.user);
        while (keyIndex < keys.size() && keys[keyIndex] < record.key)
            ++keyIndex;
        if (keyIndex < keys.size() && keys[keyIndex] == record.key)
            equals[keyIndex].set(record.user);
    }
    vector<Record>().swap(records);
    sort(dn.begin(), dn.end());
    Evaluator evaluator(keys, attributeOf, equals, exists);
    for (const string &text : expressions) {
        size_t pos = 0;
        Bits answer = evaluator.parse(text, pos);
        bool first = true;
        for (auto [id, user] : dn) {
            if (!answer[user]) continue;
            if (!first) io.put(' ');
            io.write(id);
            first = false;
        }
        io.put('\n');
    }
}
