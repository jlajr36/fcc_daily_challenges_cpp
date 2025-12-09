#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string repeat_vowels(string words) {
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string new_words = "";
    int vowel_count = 0;

    for (char c : words) {
        bool is_vowel = find(vowels.begin(), vowels.end(), c) != vowels.end();
        if (is_vowel) {
            new_words += c;
            if (vowel_count >= 1) {
                for (int i = 0; i < vowel_count; i++) {
                    new_words += tolower(c);
                }
            }
            vowel_count++;
        } else {
            new_words += c;
        }
    }
    return new_words;
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(repeat_vowels("hello world") == "helloo wooorld");
    check(repeat_vowels("freeCodeCamp") == "freeeCooodeeeeCaaaaamp");
    check(repeat_vowels("AEIOU") == "AEeIiiOoooUuuuu");
    check(repeat_vowels("I like eating ice cream in Iceland") == "I liikeee eeeeaaaaatiiiiiing iiiiiiiceeeeeeee creeeeeeeeeaaaaaaaaaam iiiiiiiiiiin Iiiiiiiiiiiiceeeeeeeeeeeeelaaaaaaaaaaaaaand");
}
