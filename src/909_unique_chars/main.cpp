#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool all_unique(string pharse) {
    unordered_map<char, int> values;
    for (char ph : pharse) {
        auto it = values.find(ph);
        if (it == values.end()) {
            values[ph] = 1;
        } else {
            values[ph] += 1;
        }
    }
    for (auto i : values) {
        //cout << i.first << ": " << i.second << endl;
        if (i.second >= 2) {
            return false;
        }
    }
    return true;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(all_unique("abc") == true);
    check(all_unique("aA") == true);
    check(all_unique("QwErTy123!@") == true);
    check(all_unique("~!@#$%^&*()_+") == true);
    check(all_unique("hello") == false);
    check(all_unique("freeCodeCamp") == false);
    check(all_unique("!@#*$%^&*()aA") == false);
}
