#include <iostream>
#include <vector>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

using namespace std;

long long sumOfSquares(long long value) {
    return value * (value + 1) * (2 * value + 1) / 6;
}

int main() {
    vector<pair<long long, long long>> testCases = {
        {5,     55},
        {10,    385},
        {25,    5525},
        {500,   41791750},
        {1000,  333833500},
        {2000,  2672671000},  // <-- this expected result is incorrect
        {2000,  2668667000},  // Additional test for large input
    };

    int passCount = 0;

    for (const auto& [input, expected] : testCases) {
        long long result = sumOfSquares(input);
        if (result == expected) {
            cout << GREEN << "PASS" << RESET << ": sumOfSquares(" << input << ") = " << result << "\n";
            ++passCount;
        } else {
            cout << RED << "FAIL" << RESET << ": sumOfSquares(" << input << ") = " << result << " (expected " << expected << ")\n";
        }
    }

    cout << "\n" << passCount << "/" << testCases.size() << " tests passed.\n";

    return 0;
}