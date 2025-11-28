#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <array>

using namespace std;

string space_jam(const string& str) {
    string temp = str;
    temp.erase(remove_if(temp.begin(), temp.end(),
                        [](unsigned char ch) { return isspace(ch); }),
                        temp.end());
    for (char& c : temp) {
        c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
    }
    string out;
    for (size_t i = 0; i < temp.size(); i++) {
        out += temp[i];
        if (i + 1 < temp.size()) {
            out += "  ";
        }
    }
    return out;
}

int main() {
    array<pair<string, string>, 5> tests = {{
        {"freeCodeCamp", "F  R  E  E  C  O  D  E  C  A  M  P"},
        {"   free   Code   Camp   ", "F  R  E  E  C  O  D  E  C  A  M  P"},
        {"Hello World?!", "H  E  L  L  O  W  O  R  L  D  ?  !"},
        {"C@t$ & D0g$", "C  @  T  $  &  D  0  G  $"},
        {"allyourbase", "A  L  L  Y  O  U  R  B  A  S  E"}
    }};

    for (const auto& [str, expected] : tests) {
        string out = space_jam(str);
        cout << "out: " << out << endl;
        cout << "expected: " << expected << endl;
        cout << (out == expected ? "PASS" : "FAIL") << endl;
    }

    return 0;
}