#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(const string& str, char del) {
    vector<string> parts;
    stringstream ss(str);
    string part;
    while (getline(ss, part, del)) {
        parts.push_back(part);
    }
    return parts;
}

/*  Sort the interior letters of each word (keep first & last unchanged) */
string jbelmu(const string& str) {
    vector<string> parts = split(str, ' ');
    vector<string> words;

    for (const string& s : parts) {
        if (s.size() > 2) {
            char first = s.front();
            char last  = s.back();

            string middle = s.substr(1, s.size() - 2);
            sort(middle.begin(), middle.end());

            // build the new word – convert chars to 1‑char strings first
            string newWord = string(1, first) + middle + string(1, last);
            words.push_back(newWord);
        } else {
            words.push_back(s);
        }
    }

    // re‑assemble the sentence
    string out;
    for (size_t i = 0; i < words.size(); ++i) {
        out += words[i];
        if (i + 1 < words.size()) out += ' ';
    }
    cout << out << endl;
    return out;
}

int main() {
    cout << (jbelmu("hello world") == "hello wlord" ? "PASS" : "FAIL") << endl;
    cout << (jbelmu("i love jumbled text") == "i love jbelmud text" ? "PASS" : "FAIL") << endl;
    cout << (jbelmu("freecodecamp is my favorite place to learn to code") ==
               "faccdeeemorp is my faiortve pacle to laern to cdoe"
               ? "PASS" : "FAIL") << endl;
    cout << (jbelmu("the quick brown fox jumps over the lazy dog") ==
               "the qciuk borwn fox jmpus oevr the lazy dog"
               ? "PASS" : "FAIL") << endl;
    return 0;
}