#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string remove_whitespace(const string& str) {
    string temp = str;
    temp.erase(remove_if(temp.begin(), temp.end(),
                         [](unsigned char ch) {return isspace(ch); }),
                         temp.end());
    return temp;
}

string sort_word(const string& str) {
    string result = str;
    sort(result.begin(), result.end());
    return result;
}

string to_lower(const string& str) {
    string result = str;
    transform(result.begin(),
              result.end(),
              result.begin(),
              [](unsigned char c){ return tolower(c);});
    return result;
}

bool are_anagrams(const string& str1, const string& str2) {
    string value1 = sort_word(to_lower(remove_whitespace(str1)));
    string value2 = sort_word(to_lower(remove_whitespace(str2)));
    return value1 == value2;
}

int main() {

    cout << (are_anagrams("listen", "silent") ? "PASS" : "FAIL") << endl;
    cout << (are_anagrams("School master", "The classroom") ? "PASS" : "FAIL") << endl;
    cout << (are_anagrams("A gentleman", "Elegant man") ? "PASS" : "FAIL") << endl;
    cout << (!are_anagrams("Hello", "World") ? "PASS" : "FAIL") << endl;
    cout << (!are_anagrams("apple", "banana") ? "PASS" : "FAIL") << endl;
    cout << (!are_anagrams("cat", "dog") ? "PASS" : "FAIL") << endl;

    return 0;
}
