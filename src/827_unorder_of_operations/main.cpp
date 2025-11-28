#include <iostream>
#include <vector>
#include <string>

using namespace std;

int evaluate(vector<int> nums, vector<char> ops) {
    int result = nums[0];
    int ops_size = ops.size();
    for (int i = 1; i < nums.size(); i++) {
        char op = ops[(i-1)%ops_size];
        int num = nums[i];
        if (op == '+') {
            result += num;
        } else if (op == '-') {
            result -= num;
        } else if (op == '*') {
            result *= num;
        } else if (op == '/') {
            result /= num;
        } else if (op == '%') {
            result %= num;
        }
    }
    return result;
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(evaluate({5, 6, 7, 8, 9}, {'+', '-'}) == 3);
    check(evaluate({17, 61, 40, 24, 38, 14}, {'+', '%'}) == 38);
    check(evaluate({20, 2, 4, 24, 12, 3}, {'*', '/'}) == 60);
    check(evaluate({11, 4, 10, 17, 2}, {'*', '*', '%'}) == 30);
    check(evaluate({33, 11, 29, 13}, {'/', '-'}) == -2);
}