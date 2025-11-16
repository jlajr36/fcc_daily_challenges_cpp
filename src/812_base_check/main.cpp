#include <iostream>
#include <tuple>
#include <array>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;

//string allowedChars(int base) {
//    if (base < 2 || base > 36) return "";
//    const string digits = "0123456789abcdefghijklmnopqrstuvwxyz";
//    return digits.substr(0, base);
//}

//bool isValidNumber(const string& str, int base) {
//    string lowered = str;
//    transform(lowered.begin(), lowered.end(), lowered.begin(),
//        [](unsigned char c){return tolower(c);});
//    const string allowed = allowedChars(base);
//    for (char c : lowered) {
//        if (allowed.find(c) == string::npos) {
//            return false;
//        }
//    }
//    return true;
//}

bool isValidNumber(const string& str, int base) {
    if (base < 2 || base > 36) return false;

    static const unordered_map<int, string> baseDigits = []{
        unordered_map<int, string> m;
        for (int b = 2; b <= 36; ++b) {
            string digits;
            for (int i = 0; i < b; ++i)
                digits += (i < 10) ? ('0' + i) : ('a' + i - 10);
            m[b] = digits;
        }
        return m;
    }();

    const string& digits = baseDigits.at(base);
    for (char c : str) {
        char lc = tolower(static_cast<unsigned char>(c));
        if (digits.find(lc) == string::npos) return false;
    }
    return true;
}

int main() {
    constexpr array<tuple<const char*, int, bool>, 16> data{{
        {"10101",      2,  true},
        {"10201",      2,  false},
        {"76543210",   8,  true},
        {"9876543210", 8,  false},
        {"9876543210", 10, true},
        {"ABC",        10, false},
        {"ABC",        16, true},
        {"Z",          36, true},
        {"ABC",        20, true},
        {"4B4BA9",     16, true},
        {"5G3F8F",     16, false},
        {"5G3F8F",     17, true},
        {"abc",        10, false},
        {"abc",        16, true},
        {"AbC",        16, true},
        {"z",          36, true}
    }};

    for (const auto& [str, base, expected] : data) {
        bool result = isValidNumber(str, base);
        cout << (result == expected ? "PASS" : "FAIL") << endl;
    }
    return 0;
}
