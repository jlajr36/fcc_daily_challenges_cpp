#include <iostream>
#include <cmath>

bool isPerfectSquare(double square) {
    if (square < 0) {return false;}
    int root = static_cast<int>(sqrt(square));
    return root * root == square;
}

void check(bool status) {
    std::cout << (status ? "PASS" : "FAIL") << std::endl;
}

int main() {
    check(isPerfectSquare(9) == true);
    check(isPerfectSquare(49) == true);
    check(isPerfectSquare(1) == true);
    check(isPerfectSquare(2) == false);
    check(isPerfectSquare(99) == false);
    check(isPerfectSquare(-9) == false);
    check(isPerfectSquare(0) == true);
    check(isPerfectSquare(25281) == true);
}