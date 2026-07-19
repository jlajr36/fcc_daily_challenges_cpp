#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string removeChar(const string& str, char ch) {
    string result = str;
    result.erase(remove(result.begin(), result.end(), ch), result.end());
    return result;
}

vector<string> split(const string& str, char delimiter) {
    stringstream ss(str);
    string token;
    vector<string> parts;
    while (getline(ss, token, delimiter)) {
        parts.push_back(token);
    }
    return parts;
}

string getLongestWord(string str) {
    str = removeChar(str, '.');
    vector<string> parts = split(str, ' ');
    string longestStr = "";
    for (const string& part : parts) {
        if (part.size() > longestStr.size()) {
            longestStr = part;
        }
    }
    return longestStr;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(getLongestWord("coding is fun") == "coding");
    check(getLongestWord("Coding challenges are fun and educational.") == "educational");
    check(getLongestWord("This sentence has multiple long words.") == "sentence");
}
