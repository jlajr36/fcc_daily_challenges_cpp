#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string decode(string str) {
    vector<char> stack;
    for (char &c : str) {
        if (c == ')') {
            vector<char> buffer;
            while (!stack.empty() && stack.back() != '(') {
                buffer.push_back(stack.back());
                stack.pop_back();
            }
            if (!stack.empty()) stack.pop_back(); // remove '('
            
            // push buffer back in reverse order (to decode)
            for (char &b : buffer) {
                stack.push_back(b);
            }
        } else {
            stack.push_back(c);
        }
    }
    return string(stack.begin(), stack.end());
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(decode("(f(b(dc)e)a)") == "abcdef");
    check(decode("((is?)(a(t d)h)e(n y( uo)r)aC)") == "Can you read this?");
    check(decode("f(Ce(re))o((e(aC)m)d)p") == "freeCodeCamp");
}