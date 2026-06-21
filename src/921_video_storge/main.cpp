#include <iostream>
#include <variant>

using namespace std;

void printVariant(const variant<int, string>& _variant) {
    if (holds_alternative<int>(_variant)) {
        cout << get<int>(_variant) << endl;
    } else {
        cout << get<string>(_variant) << endl;
    }
}

bool isValidVideoUnit(const string& unit) {
    return unit == "B" || unit == "KB" || unit == "MB" || unit == "GB";
}

bool isValidDriveUnit(const string& unit) {
    return unit == "GB" || unit == "TB";
}

variant<int, string> numberOfVideos(double v_size, string v_size_u, double hd_cap, string hd_unit) {
    if (!isValidVideoUnit(v_size_u)) {return "Invalid video unit";}
    if (!isValidDriveUnit(hd_unit)) {return "Invalid drive unit";}
    if (v_size_u == "KB") {v_size = v_size * 1000;}
    if (v_size_u == "MB") {v_size = v_size * 1000000;}
    if (v_size_u == "GB"){v_size = v_size * 1000000000;}
    if (hd_unit == "GB"){hd_cap = hd_cap * 1000000000;}
    if (hd_unit == "TB"){hd_cap = hd_cap * 1000000000000;}
    return int(hd_cap / v_size);
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    printVariant(numberOfVideos(500, "MB", 100, "GB"));
    check(numberOfVideos(500, "MB", 100, "GB") == variant<int, string>{200});
    printVariant(numberOfVideos(1, "TB", 10, "TB"));
    check(numberOfVideos(1, "TB", 10, "TB") == variant<int, string>{"Invalid video unit"});
    printVariant(numberOfVideos(2000, "MB", 100000, "MB"));
    check(numberOfVideos(2000, "MB", 100000, "MB") == variant<int, string>{"Invalid drive unit"});
    printVariant(numberOfVideos(500000, "KB", 2, "TB"));
    check(numberOfVideos(500000, "KB", 2, "TB") == variant<int, string>{4000});
    printVariant(numberOfVideos(1.5, "GB", 2.2, "TB"));
    check(numberOfVideos(1.5, "GB", 2.2, "TB") == variant<int, string>{1466});
}