#include <iostream>
#include <vector>

using namespace std;

void print_seq(vector<int> seq) {
    for (int num : seq) {
    cout << num << ",";
    }
    cout << endl;
}

vector<int> tribonacci_sequence(const vector<int>& seq, int count) {
    if (count == 0) {
        return {};
    }

    int seq_size = seq.size();
    if (count <= seq_size) {
        return vector<int>(seq.begin(), seq.begin() + count);
    }

    vector<int> result = seq;
    for (int i = seq_size; i < count; i++) {
        result.push_back(result[i-1] + result[i-2] + result[i-3]);
    }
    return result;
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(tribonacci_sequence({0, 0, 1}, 20) == vector<int>{0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513});
    check(tribonacci_sequence({21, 32, 43}, 1) == vector<int>{21});
    check(tribonacci_sequence({0, 0, 1}, 0) == vector<int>{});
    check(tribonacci_sequence({10, 20, 30}, 2) == vector<int>{10, 20});
    check(tribonacci_sequence({10, 20, 30}, 3) == vector<int>{10, 20, 30});
    check(tribonacci_sequence({123, 456, 789}, 8) == vector<int>{123, 456, 789, 1368, 2613, 4770, 8751, 16134});
}
