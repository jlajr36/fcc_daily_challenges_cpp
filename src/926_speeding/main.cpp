#include <iostream>
#include <vector>

using namespace std;

vector<double> speeding(const vector<int>& speeds, int limit) {
    double count = 0;
    double average = 0;
    double sum = 0;

    for (double speed : speeds) {
        if (speed > limit) {
            count++;
            sum += (speed - limit);
        }
    }

    if (count > 0) {
        average = sum / count;
    }

    // cout << "count: " << count << endl;
    // cout << "sum: " << sum << endl;
    // cout << "average: " << average << endl;

    return {count, average};
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(speeding({50, 60, 55}, 60) == vector<double>{0, 0});
    check(speeding({58, 50, 60, 55}, 55) == vector<double>{2, 4});
    check(speeding({61, 81, 74, 88, 65, 71, 68}, 70) == vector<double>{4, 8.5});
    check(speeding({100, 105, 95, 102}, 100) == vector<double>{2, 3.5});
    check(speeding({40, 45, 44, 50, 112, 39}, 55) == vector<double>{1, 57});
}
