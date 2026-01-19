#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string costToFill(float tankSize, float fuelLevel, float pricePerGallon) {    
    float total = (tankSize - fuelLevel) * pricePerGallon;
    ostringstream oss;
    oss << '$' << fixed << setprecision(2) << total;
    return oss.str();
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(costToFill(20, 0, 4.00) == "$80.00");
    check(costToFill(15, 10, 3.50) == "$17.50");
    check(costToFill(18, 9, 3.25) == "$29.25");
    check(costToFill(12, 12, 4.99) == "$0.00");
    check(costToFill(15, 9.5, 3.98) == "$21.89");
}