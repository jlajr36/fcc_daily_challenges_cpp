#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

string intToHex(int value) {
    stringstream ss;
    ss << hex << nouppercase << setw(2) << setfill('0') << value;
    return ss.str();
}

string rgb_to_hex(const string& rgb) {
    int r, g, b;

    // Validate format
    if (sscanf(rgb.c_str(), "rgb(%d, %d, %d)", &r, &g, &b) != 3) {
        throw invalid_argument("Invalid RGB format: " + rgb);
    }

    // Clamp values 0–255
    r = max(0, min(255, r));
    g = max(0, min(255, g));
    b = max(0, min(255, b));

    return '#' + intToHex(r) + intToHex(g) + intToHex(b);
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    try {
        check(rgb_to_hex("rgb(255, 255, 255)") == "#ffffff");
        check(rgb_to_hex("rgb(1, 11, 111)") == "#010b6f");
        check(rgb_to_hex("rgb(173, 216, 230)") == "#add8e6");
        check(rgb_to_hex("rgb(79, 123, 201)") == "#4f7bc9");

        // Extra tests
        check(rgb_to_hex("rgb(999, -20, 260)") == "#ff00ff");  // after clamping
    } 
    catch (const exception& e) {
        cout << "ERROR: " << e.what() << endl;
    }
}
