#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <unordered_map>

using namespace std;

vector<string> get_words(string sentence) {
    // Normalize input
    for (char &c : sentence) {
        if (c == ',' || c == '.' || c == '!') {
            c = ' ';
        }
        c = tolower(static_cast<unsigned char>(c));
    }

    vector<string> words;
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    // frequency + first appearance index
    unordered_map<string, pair<int, int>> info;

    for (int i = 0; i < words.size(); i++) {
        if (info.find(words[i]) == info.end()) {
            info[words[i]] = {1, i};
        } else {
            info[words[i]].first++;
        }
    }

    vector<pair<string, pair<int, int>>> freq(info.begin(), info.end());

    sort(freq.begin(), freq.end(),
        [](const auto &a, const auto &b) {
            if (a.second.first != b.second.first)
                return a.second.first > b.second.first; // frequency
            return a.second.second < b.second.second;   // first appearance
        });

    vector<string> out;
    for (int i = 0; i < 3 && i < freq.size(); i++) {
        out.push_back(freq[i].first);
    }

    return out;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(get_words("Coding in Python is fun because coding Python allows for coding in Python easily while coding")
          == vector<string>{"coding", "python", "in"});

    check(get_words("I like coding. I like testing. I love debugging!")
          == vector<string>{"i", "like", "coding"});

    check(get_words("Debug, test, deploy. Debug, debug, test, deploy. Debug, test, test, deploy!")
          == vector<string>{"debug", "test", "deploy"});
}
