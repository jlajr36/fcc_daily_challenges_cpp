#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> array_diff(const vector<string>& a, const vector<string>& b) {
    vector<string> out;
    for (string s : a) {
        auto it = find(b.begin(), b.end(), s);
        if (it == b.end()) {
            out.push_back(s);
        }
    }
    for (string s : b) {
        auto it = find(a.begin(), a.end(), s);
        if (it == a.end()) {
            out.push_back(s);
        }
    }
    sort(out.begin(), out.end());
    return out;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(array_diff({"apple", "banana"}, {"apple", "banana", "cherry"}) == vector<string>{"cherry"});
    check(array_diff({"apple", "banana", "cherry"}, {"apple", "banana"}) == vector<string>{"cherry"});
    check(array_diff({"one", "two", "three", "four", "six"}, {"one", "three", "eight"}) == vector<string>{"eight", "four", "six", "two"});
    check(array_diff({"two", "four", "five", "eight"}, {"one", "two", "three", "four", "seven", "eight"}) == vector<string>{"five", "one", "seven", "three"});
    check(array_diff({"I", "like", "freeCodeCamp"}, {"I", "like", "rocks"}) == vector<string>{"freeCodeCamp", "rocks"});
}
