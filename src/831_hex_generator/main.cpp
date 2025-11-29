#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>
#include <string>

// Helper: return a random integer in the inclusive range [a, b]
int rand_int(int a, int b, std::mt19937& gen) {
    std::uniform_int_distribution<int> dist(a, b);
    return dist(gen);
}

// Convert a colour name to a 6‑character hex string
std::string generate_hex(const std::string& color) {
    static std::random_device rd;
    static std::mt19937 gen(rd());          // shared engine for all calls

    if (color != "red" && color != "green" && color != "blue")
        return "Invalid color";

    int r = 0, g = 0, b = 0;

    if (color == "red") {
        r = rand_int(128, 255, gen);        // bright red
        g = rand_int(0, r - 1, gen);
        b = rand_int(0, r - 1, gen);
    }
    else if (color == "green") {
        g = rand_int(128, 255, gen);        // bright green
        r = rand_int(0, g - 1, gen);
        b = rand_int(0, g - 1, gen);
    }
    else { // color == "blue"
        b = rand_int(128, 255, gen);        // bright blue
        r = rand_int(0, b - 1, gen);
        g = rand_int(0, b - 1, gen);
    }

    // Format as two‑digit uppercase hex for each component
    std::ostringstream oss;
    oss << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << r
        << std::setw(2) << std::setfill('0') << g
        << std::setw(2) << std::setfill('0') << b;
    return oss.str();
}

// Example driver
int main() {
    std::cout << "red   -> " << generate_hex("red")   << '\n';
    std::cout << "green -> " << generate_hex("green") << '\n';
    std::cout << "blue  -> " << generate_hex("blue")  << '\n';
    std::cout << "yellow-> " << generate_hex("yellow") << '\n';
    return 0;
}
