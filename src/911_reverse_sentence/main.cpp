#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string reverse_sentence(const string& sentence) {
    stringstream ss(sentence);
    vector<string> words;
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    string out;
    for (size_t i = 0; i < words.size(); i++) {
        if (i > 0) out += " ";
        out += words[i];
    }
    return out;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(reverse_sentence("world hello") == "hello world");
    check(reverse_sentence("push commit git") == "git commit push");
    check(reverse_sentence("npm  install   apt    sudo") == "sudo apt install npm");
    check(reverse_sentence("import    default   function  export") == "export function default import");
}
