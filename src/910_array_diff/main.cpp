#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<string> array_diff(const vector<string>& a, const vector<string>& b) {
    unordered_set<string> setA(a.begin(), a.end());
    unordered_set<string> setB(b.begin(), b.end());

    vector<string> out;

    for (const auto& s : setA) {
        if (!setB.count(s)) {
            out.push_back(s);
        }
    }

    for (const auto& s : setB) {
        if (!setA.count(s)) {
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
