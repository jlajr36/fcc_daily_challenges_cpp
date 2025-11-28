#include <cmath>
#include <iostream>

using namespace std;

bool is_unnatural_prime(int num) {
    int n = abs(num);
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    int limit = static_cast<int>(sqrt(n)) + 1;
    for (int divisor = 3; divisor <= limit; divisor+=2) {
        if (n % divisor == 0) {
            return false;
        }
    }
    return true;
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(is_unnatural_prime(1)    == false); // 1 is not prime
    check(is_unnatural_prime(-1)   == false); // negative 1 → not prime
    check(is_unnatural_prime(19)   == true);  // positive prime
    check(is_unnatural_prime(-23)  == true);  // negative prime (abs → 23)
    check(is_unnatural_prime(0)    == false); // 0 is not prime
    check(is_unnatural_prime(97)   == true);  // larger prime
    check(is_unnatural_prime(-61)  == true);  // negative prime
    check(is_unnatural_prime(99)   == false); // composite (9 × 11)
    check(is_unnatural_prime(-44)  == false); // negative composite
    check(is_unnatural_prime(2)    == true);  // smallest prime
    check(is_unnatural_prime(-2)   == true);  // negative prime
    check(is_unnatural_prime(3)    == true);  // odd prime
    check(is_unnatural_prime(4)    == false); // even composite
    check(is_unnatural_prime(25)   == false); // square of a prime
    check(is_unnatural_prime(31)   == true);  // two‑digit prime
    check(is_unnatural_prime(49)   == false); // 7²
    check(is_unnatural_prime(73)   == true);  // prime > 70
    check(is_unnatural_prime(-91)  == false); // negative composite
    check(is_unnatural_prime(121)  == false); // 11²
    check(is_unnatural_prime(997)  == true);  // three‑digit prime
    return 0;
}