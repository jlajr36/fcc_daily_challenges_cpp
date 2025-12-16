#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int parse_roman_numeral(string numeral) {
    unordered_map<char, int> nums = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    reverse(numeral.begin(), numeral.end());
    int total = nums[numeral[0]];
    int current = 0;
    int pervious = nums[numeral[0]];
    for (int i = 1; i < numeral.size(); i++) {
        current = nums[numeral[i]];
        if (current < pervious) {
            total -= current;
        } else {
            total += current;
        }
        pervious = current;
    }
    return total;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(parse_roman_numeral("III") == 3);
    check(parse_roman_numeral("IV") == 4);
    check(parse_roman_numeral("XXVI") == 26);
    check(parse_roman_numeral("XCIX") == 99);
    check(parse_roman_numeral("CDLX") == 460);
    check(parse_roman_numeral("DIV") == 504);
    check(parse_roman_numeral("MMXXV") == 2025);
}
