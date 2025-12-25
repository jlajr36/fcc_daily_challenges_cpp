#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> find_missing_numbers(vector<int> numbers) {
    int min = *min_element(numbers.begin(), numbers.end());
    int max = *max_element(numbers.begin(), numbers.end());
    vector<int> all(max - min + 1);
    iota(all.begin(), all.end(), min);
    vector<int> out = {};
    for (int a : all) {
        auto it = find(numbers.begin(), numbers.end(), a);
        if (it == numbers.end()) {
            out.push_back(a);
        }
    }
    return out;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(find_missing_numbers({1, 3, 5}) == vector<int>{2, 4});
    check(find_missing_numbers({1, 2, 3, 4, 5}) == vector<int>{});
    check(find_missing_numbers({1, 10}) == vector<int>{2, 3, 4, 5, 6, 7, 8, 9});
    check(find_missing_numbers({10, 1, 10, 1, 10, 1}) == vector<int>{2, 3, 4, 5, 6, 7, 8, 9});
    check(find_missing_numbers({3, 1, 4, 1, 5, 9}) == vector<int>{2, 6, 7, 8});
    check(find_missing_numbers({1, 2, 3, 4, 5, 7, 8, 9, 10, 12, 6, 8, 9, 3, 2, 10, 7, 4}) == vector<int>{11});
}
