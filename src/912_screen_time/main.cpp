#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool too_much_screen_time(vector<int> hours) {
    // ****
    for(int hour : hours) {
        if (hour >= 10) {return true;}
    }

    // ****
    int group_size = 3;
    int count = 0;
    while(count <= hours.size() - group_size) {
        vector<int> sub(hours.begin() + count, hours.begin() + count + group_size);
        int sum = accumulate(sub.begin(), sub.end(), 0);
        if (sum / sub.size() >= 8) { return true; }
        count++;
    }

    // ****
    int sum = accumulate(hours.begin(), hours.end(), 0);
    double weekavg = sum / hours.size();
    if (weekavg >= 6) {return true;}

    // ****
    return false;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(too_much_screen_time({1, 2, 3, 4, 5, 6, 7}) == false);
    check(too_much_screen_time({7, 8, 8, 4, 2, 2, 3}) == false);
    check(too_much_screen_time({5, 6, 6, 6, 6, 6, 6}) == false);
    check(too_much_screen_time({1, 2, 3, 11, 1, 3, 4}) == true);
    check(too_much_screen_time({1, 2, 3, 10, 2, 1, 0}) == true);
    check(too_much_screen_time({3, 3, 5, 8, 8, 9, 4}) == true);
    check(too_much_screen_time({3, 9, 4, 8, 5, 7, 6}) == true);
}
