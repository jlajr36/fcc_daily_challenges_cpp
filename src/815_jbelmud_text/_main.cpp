#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string str, char del) {
    vector<string> parts;
    stringstream ss(str);
    string part;
    while (getline(ss, part, del)) {
        parts.push_back(part);
    }
    return parts;
}

string jbelmu(string str) {
    vector<string> parts = split(str, ' ');
    vector<string> words;
    for (string s : parts) {
        if (s.size() > 2) {
            char first = s[0];
            char last = s[s.size() - 1];
            string middle = s.substr(1, s.size() - 2);
            sort(middle.begin(), middle.end());
            string newString = first + middle + last;
            words.push_back(newString);
        } else {
            words.push_back(s);
        }
    }
    string out;
    for (int i = 0; i < words.size(); i++) {
        if (i == words.size() - 1) {
            out += words[i];
        } else {
            out += (words[i] + ' ');
        }
    }
    cout << out << endl;
    return out;
}

int main()
{
    cout << (jbelmu("hello world") == "hello wlord" ? "PASS" : "FAIL") << endl;
    cout << (jbelmu("i love jumbled text") == "i love jbelmud text" ? "PASS" : "FAIL") << endl;
    cout << (jbelmu("freecodecamp is my favorite place to learn to code") == "faccdeeemorp is my faiortve pacle to laern to cdoe" ? "PASS" : "FAIL") << endl;
    cout << (jbelmu("the quick brown fox jumps over the lazy dog") == "the qciuk borwn fox jmpus oevr the lazy dog" ? "PASS" : "FAIL") << endl;
    return 0;
}