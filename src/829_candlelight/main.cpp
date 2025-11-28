#include <iostream>

using namespace std;

int burn_candles(int candles, int rate) {
    int total = 0;
    int leftovers = 0;
    while (candles > 0) {
        total += candles;
        leftovers += candles;
        candles = leftovers / rate;
        leftovers = leftovers % rate;
    }
    return total;
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(burn_candles(7, 2)); //should return 13
    check(burn_candles(10, 5)); //should return 12
    check(burn_candles(20, 3)); //should return 29
    check(burn_candles(17, 4)); //should return 22
    check(burn_candles(2345, 3)); //should return 3517
}