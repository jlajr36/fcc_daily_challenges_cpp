#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string build_acronym(string name_str) {
    vector<string> ignore = {"a", "for", "an", "and", "by", "of"};
    string acronym = "";
    stringstream ss(name_str);
    string temp_str;
    char delim = ' ';
    while (getline(ss, temp_str, delim)) {
        auto it = find(ignore.begin(), ignore.end(), temp_str);
        if (it == ignore.end()) {
            acronym += (char)toupper(temp_str[0]);
        }
    }
    return acronym;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(build_acronym("Search Engine Optimization") == "SEO");
    check(build_acronym("Frequently Asked Questions") == "FAQ");
    check(build_acronym("National Aeronautics and Space Administration") == "NASA");
    check(build_acronym("Federal Bureau of Investigation") == "FBI");
    check(build_acronym("For your information") == "FYI");
    check(build_acronym("By the way") == "BTW");
    check(build_acronym("An unstoppable herd of waddling penguins overtakes the icy mountains and sings happily") == "AUHWPOTIMSH");
}