#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> split(string str) {
    regex re("[ \\-_]+");
    sregex_token_iterator it(str.begin(), str.end(), re, -1);
    sregex_token_iterator end;
    vector<string> parts;
    while (it != end) {
        parts.push_back(*it++);
    }
    return parts;
}

string trim(string str) {
    auto start = find_if_not(str.begin(), str.end(), [](unsigned char c){ return isspace(c); });
    auto end = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char c){ return isspace(c); }).base();
    return (start < end ? string(start, end) : "");
}

string lower(string str) {
    for (char &c : str) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return str;
}

string to_camel_case(string str) {
    vector<string> parts = split(str);
    string new_name = "";
    int index = 0;
    for (const auto& part : parts) {
        string trimmed = trim(part);
        string lowered = lower(trimmed);
        if (index > 0) {
            lowered[0] = toupper(lowered[0]);
        }
        new_name += lowered;
        index++;
    }
    return new_name;
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(to_camel_case("hello world") == "helloWorld");
    check(to_camel_case("HELLO WORLD") == "helloWorld");
    check(to_camel_case("secret agent-X") == "secretAgentX");
    check(to_camel_case("FREE cODE cAMP") == "freeCodeCamp");
    check(to_camel_case("ye old-_-sea  faring_buccaneer_-_with a - peg__leg----and a_parrot_ _named- _squawk") == "yeOldSeaFaringBuccaneerWithAPegLegAndAParrotNamedSquawk");
}
