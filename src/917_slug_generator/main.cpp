#include <algorithm>
#include <cctype>
#include <string>
#include <regex>
#include <iostream>

using namespace std;

/*  Convert a string to a URL‑slug:
 *  – lower‑case letters
 *  – keep only alphanumerics and spaces
 *  – collapse consecutive spaces to a single space
 *  – trim leading/trailing spaces
 *  – replace each remaining space with "%20"
 */
string generate_slug(const string& str) {
    string s = str;

    // 1. lower‑case
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c){ return tolower(c); });

    // 2. keep only alphanumerics and spaces
    s.erase(remove_if(s.begin(), s.end(),
                      [](unsigned char c){
                          return !isalnum(c) && !isspace(c);
                      }),
            s.end());

    // 3. collapse multiple spaces to one
    s = regex_replace(s, regex(R"(\s+)"), " ");

    // 4. trim leading / trailing spaces
    s = regex_replace(s, regex(R"(^\s+|\s+$)"), "");

    // 5. replace remaining spaces with "%20"
    s = regex_replace(s, regex(R"(\s)"), "%20");

    return s;
}

/* Simple test helper */
void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(generate_slug("helloWorld") == "helloworld");
    check(generate_slug("hello world!") == "hello%20world");
    check(generate_slug(" hello-world ") == "helloworld");
    check(generate_slug("hello  world") == "hello%20world");
    check(generate_slug("  ?H^3-1*1]0! W[0%R#1]D  ") == "h3110%20w0r1d");
}
