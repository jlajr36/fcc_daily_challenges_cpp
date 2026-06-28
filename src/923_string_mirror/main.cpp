#include <iostream>
#include <algorithm>
#include <string>

bool isMirror(std::string str1, std::string str2) {
    std::string s1, s2;

    for (char c : str1) {
        if (isalpha(static_cast<unsigned char>(c))) {
            s1 += static_cast<unsigned char>(c);
        }
    }

    for (char c : str2) {
        if (isalpha(static_cast<unsigned char>(c))) {
            s2 += static_cast<unsigned char>(c);
        }
    }
    reverse(s2.begin(), s2.end());

    return s1 == s2;
}

void check(bool status) {
    std::cout << (status ? "PASS" : "FAIL") << std::endl;
}

int main() {
    check(isMirror("helloworld", "helloworld") == false);
    check(isMirror("Hello World", "dlroW olleH") == true);
    check(isMirror("RaceCar", "raCecaR") == true);
    check(isMirror("RaceCar", "RaceCar") == false);
    check(isMirror("Mirror", "rorrim") == false);
    check(isMirror("Hello World", "dlroW-olleH") == true);
    check(isMirror("Hello World", "!dlroW !olleH") == true);
}