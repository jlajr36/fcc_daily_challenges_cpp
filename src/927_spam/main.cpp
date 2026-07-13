#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool isSpam(string number) {
    string cc = "";
    string ac = "";
    string ec = "";
    string ln = "";

    regex pattern(R"(^\+(\d{1,3}) \((\d{3})\) (\d{3})-(\d{4})$)");
    smatch match;
    if (regex_match(number, match, pattern)) {
       cc = match[1];
       ac = match[2];
       ec = match[3];
       ln = match[4];
    }

    // cout << "cc: " << cc << endl;
    // cout << "ac: " << ac << endl;
    // cout << "ec: " << ec << endl;
    // cout << "ln: " << ln << endl;

    // Country code is greater than 2 digits long or doesn't begin with a zero (0).
    if (cc.size() > 2 || cc[0] != '0') {
        // cout << "cc code" << endl;
        return true;
    }

    // Area code is greater than 900 or less than 200.
    int ac_int = stoi(ac);
    if (ac_int > 900 || ac_int < 200) {
        // cout << "ac code" << endl;
        return true;
    }

    // Sum of first three digits of the local number appears within last four digits of the local number.
    int sum = 0;
    for (char c : ec) {
        int num = stoi(string(1, c));
        sum += num;
    }
    string strSum = to_string(sum);
    // cout << "Sum: " << strSum << endl;
    if (ln.find(strSum) != string::npos) {
        // cout << "ln code" << endl;
        return true;
    }

    // Number has the same digit four or more times in a row.
    int digCount = 1;
    char curDig = number[0];
    for (char c : number) {
        if (isdigit(c)) {
            // cout << c << " ";
            if (c != curDig) {
                curDig = c;
                digCount = 1;
                // cout << "New Cur Dig:" << curDig << endl;
            } else {
                digCount++;
                // cout << "Dig Count: " << digCount << endl;
                if (digCount >= 4) {
                    // cout << "Four or more" << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(isSpam("+0 (200) 234-0182") == false);
    check(isSpam("+091 (555) 309-1922") == true);
    check(isSpam("+1 (555) 435-4792") == true);
    check(isSpam("+0 (955) 234-4364") == true);
    check(isSpam("+0 (155) 131-6943") == true);
    check(isSpam("+0 (555) 135-0192") == true);
    check(isSpam("+0 (555) 564-1987") == true);
    check(isSpam("+00 (555) 234-0182") == false);
}
