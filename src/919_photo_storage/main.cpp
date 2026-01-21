#include <iostream>

using namespace std;

float numberOfPhotos(float photoSizeMB, float capacityGB) {
    return static_cast<int>((capacityGB * 1000) / photoSizeMB);
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(numberOfPhotos(1, 1) == 1000);
    check(numberOfPhotos(2, 1) == 500);
    check(numberOfPhotos(4, 256) == 64000);
    check(numberOfPhotos(3.5, 750) == 214285);
    check(numberOfPhotos(3.5, 5.5) == 1571);
}