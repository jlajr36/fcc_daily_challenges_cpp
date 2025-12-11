#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, string delim) {
    vector<string> parts;
    size_t start = 0;
    size_t end = str.find(delim);
    while (end != string::npos) {
        parts.push_back(str.substr(start, end - start));
        start = end + delim.length();
        end = str.find(delim, start);
    }
    parts.push_back(str.substr(start));
    return parts;
}

bool leadingZero(string str) {
    if (str.size() == 0) return false;
    if (str == "0") return false;
    if (str.size() > 1 && str[0] == '0') return true;
    return false;
}

bool is_valid_ipv4(string ipaddr) {
    vector<string> parts = split(ipaddr, ".");
    for (int i = 0; i < parts.size(); i++) {
        if (leadingZero(parts[i])) {
            return false;
        }
        int num;
        try {
            num = stoi(parts[i]);
        } catch (...) {
            return false;
        }
        if (num < 0 || num > 255) {
            return false;
        }
    }
    return true;
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(is_valid_ipv4("192.168.1.1") == true);
    check(is_valid_ipv4("0.0.0.0") == true);
    check(is_valid_ipv4("255.01.50.111") == false);
    check(is_valid_ipv4("255.00.50.111") == false);
    check(is_valid_ipv4("256.101.50.115") == false);
    check(is_valid_ipv4("192.168.101.") == false);
    check(is_valid_ipv4("192168145213") == false);
}
