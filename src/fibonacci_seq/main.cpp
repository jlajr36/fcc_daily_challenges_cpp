#include <iostream>
#include <vector>
#include <array>
#include <cstdint>
#include <tuple>

using namespace std;

vector<int64_t> fibonacci_sequence(const vector<int64_t>& seed, size_t count) {
    if (count == 0) return {};
    if (count == 1) return {seed[0]};

    vector<int64_t> out;
    out.reserve(count);
    out.push_back(seed[0]);
    out.push_back(seed[1]);

    for (size_t i = 2; i < count; ++i) {
        int64_t next = out[i - 1] + out[i - 2];
        out.push_back(next);
    }
    return out;
}

template <typename T>
void print_vector(const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ' ';
    }
}

int main() {
    array<tuple<vector<int64_t>, int, vector<int64_t>>, 5> tests = {{
        {{0, 1}, 15, {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377}},
        {{21, 32}, 1, {21}},
        {{0, 1}, 0, {}},
        {{10, 20}, 2, {10, 20}},
        {{123456789, 987654321}, 5, {123456789, 987654321, 1111111110, 2098765431, 3209876541}}
    }};
    for (const auto& [seed, count, expected] : tests) {
        vector<int64_t> out = fibonacci_sequence(seed, count);
        cout << "Seed : ";
        print_vector(seed);
        cout << " ,Output : ";
        print_vector(out);
        cout << (out == expected ? " : PASS" : " : FAIL") << endl;
    }
}
