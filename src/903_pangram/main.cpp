#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

void print_char_vector(const std::vector<char>& v) {
    std::cout << "[ ";
    for (char c : v) std::cout << c << ' ';
    std::cout << "]\n";
}

bool is_pangram(string wrd, string pan) {
    vector<char> v_wrd;
    for (char w : wrd) {
        if (isalpha(w)) {
            char c_w = static_cast<char>(tolower(w));
            auto idx = find(v_wrd.begin(), v_wrd.end(), c_w);
            if (idx == v_wrd.end()) {
                v_wrd.push_back(c_w);
            }
        }
    }
    sort(v_wrd.begin(), v_wrd.end());
    //print_char_vector(v_wrd);

    vector<char> v_p;
    for (char p : pan) {
        v_p.push_back(p);
    }
    sort(v_p.begin(), v_p.end());
    //print_char_vector(v_p);

    return v_wrd == v_p;
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(is_pangram("hello", "helo") == true);
    check(is_pangram("hello", "hel") == false);
    check(is_pangram("hello", "helow") == false);
    check(is_pangram("hello world", "helowrd") == true);
    check(is_pangram("Hello World!", "helowrd") == true);
    check(is_pangram("Hello World!", "heliowrd") == false);
    check(is_pangram("freeCodeCamp", "frcdmp") == false);
    check(is_pangram("The quick brown fox jumps over the lazy dog.", "abcdefghijklmnopqrstuvwxyz") == true);
}
