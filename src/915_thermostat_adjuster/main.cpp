#include <iostream>

using namespace std;

string adjust_thermostat(int room, int target) {
    if (room < target) {
        return "heat";
    }
    if (room > target) {
        return "cool";
    }
    if (room == target) {
        return "hold";
    }
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(adjust_thermostat(68, 72) == "heat");
    check(adjust_thermostat(75, 72) == "cool");
    check(adjust_thermostat(72, 72) == "hold");
    check(adjust_thermostat(-20.5, -10.1) == "heat");
    check(adjust_thermostat(100, 99.9) == "cool");
    check(adjust_thermostat(0.0, 0.0) == "hold");
}
