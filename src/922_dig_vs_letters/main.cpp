#include <iostream>
#include <variant>
#include <string>
#include <cctype>

std::string digitsOrLetters(const std::string& sample) {
    int digCount = 0;
    int chrCount = 0;
    for (char c : sample) {
        if (std::isdigit(static_cast<unsigned char>(c))) {digCount++;}
        if (std::isalpha(static_cast<unsigned char>(c))) {chrCount++;}
    }
    if (digCount > chrCount) {return "digits";}
    if (chrCount > digCount) {return "letters";}
    return "tie";
}

void check(bool status) {
    std::cout << (status ? "PASS" : "FAIL") << std::endl;
}

int main() {
    check(digitsOrLetters("abc123") =="tie");
    check(digitsOrLetters("a1b2c3d") =="letters");
    check(digitsOrLetters("1a2b3c4") =="digits");
    check(digitsOrLetters("abc123!@#DEF") =="letters");
    check(digitsOrLetters("H3110 W0R1D") =="digits");
    check(digitsOrLetters("P455W0RD") =="tie");
}