#include <iostream>
#include <cstdint>
#include <stdexcept>

constexpr int64_t kMaxFactorial = 20;   // safe upper bound for int64_t

int64_t factorial(int64_t n) {
    if (n < 0) {
        throw std::invalid_argument("factorial not defined for negative numbers");
    }
    int64_t result = 1;
    for (int64_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    for (int64_t i = 0; i <= kMaxFactorial; ++i) {
        std::cout << factorial(i) << '\n';
    }
    return 0;
}