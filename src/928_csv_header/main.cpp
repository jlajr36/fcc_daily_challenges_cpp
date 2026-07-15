#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

string trim(string str) {
    size_t f_pos = str.find_first_not_of(" ");
    size_t l_pos = str.find_last_not_of(" ");
    return str.substr(f_pos, l_pos - f_pos + 1);
}

void print_string_vector(vector<string> vstr) {
    for (string s : vstr) {
        cout << s << "-";
    }
    cout << endl;
}

vector<string> split(string str, char delimiter) {
    stringstream ss(str);
    string token;
    vector<string> out;
    while (getline(ss, token, delimiter)) {
        out.push_back(token);
    }
    return out;
}

vector<string> getHeadings(string headings) {
    vector<string> _headings = split(headings, ',');
    // print_string_vector(_headings);
    int index = 0;
    for (string head : _headings) {
        _headings[index] = trim(head);
        index++;
    }
    // print_string_vector(_headings);
    return _headings;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(getHeadings("name,age,city") == vector<string>{"name", "age", "city"});
    check(getHeadings("first name,last name,phone") == vector<string>{"first name", "last name", "phone"});
    check(getHeadings("username , email , signup date ") == vector<string>{"username", "email", "signup date"});
}