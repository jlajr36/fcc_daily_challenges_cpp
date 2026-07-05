#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void print_set(set<double> _set) {
    for (double element : _set) {
        cout << element << " ";
    }
}

double secondLargest(const vector<double>& values) {
    set<double> _set;
    for (double value : values) {
        _set.insert(value);
    }
    // print_set(_set);
    vector<double> new_values(_set.begin(), _set.end());
    return new_values[new_values.size()-2];
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(secondLargest({1, 2, 3, 4}) == 3);
    check(secondLargest({20, 139, 94, 67, 31}) == 94);
    check(secondLargest({2, 3, 4, 6, 6}) == 4);
    check(secondLargest({10, -17, 55.5, 44, 91, 0}) == 55.5);
    check(secondLargest({1, 0, -1, 0, 1, 0, -1, 1, 0}) == 0);
}