#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s;
    cin >> s;
    vector<unsigned char> in;
    string h;
    while (cin >> h)
        for (size_t i = 0; i < h.size(); i += 2)
            in.push_back(stoul(h.substr(i, 2), nullptr, 16));
    size_t p = 0;
    unsigned length = 0, shift = 0;
    while (true) {
        unsigned b = in[p++];
        length |= (b & 127) << shift;
        if (!(b & 128))
            break;
        shift += 7;
    }
    vector<unsigned char> out;
    out.reserve(length);
    while (p < in.size()) {
        unsigned tag = in[p++], type = tag & 3, len, offset;
        if (type == 0) {
            len = tag >> 2;
            if (len < 60)
                ++len;
            else {
                unsigned bytes = len - 59;
                len = 0;
                for (unsigned j = 0; j < bytes; j++)
                    len |= unsigned(in[p++]) << (8 * j);
                ++len;
            }
            for (unsigned j = 0; j < len; j++)
                out.push_back(in[p++]);
        } else {
            if (type == 1) {
                len = ((tag >> 2) & 7) + 4;
                offset = ((tag >> 5) << 8) | in[p++];
            } else {
                len = (tag >> 2) + 1;
                offset = in[p++];
                offset |= unsigned(in[p++]) << 8;
            }
            for (unsigned j = 0; j < len; j++)
                out.push_back(out[out.size() - offset]);
        }
    }
    const char *hex = "0123456789abcdef";
    for (size_t i = 0; i < out.size(); i++) {
        cout << hex[out[i] >> 4] << hex[out[i] & 15];
        if (i % 8 == 7 || i + 1 == out.size())
            cout << '\n';
    }
}
