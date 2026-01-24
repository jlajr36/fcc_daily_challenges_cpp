#include <iostream>

using namespace std;

enum class unitSize {
    B = 1,
    KB = 1000,
    MB = 1000000,
    GB = 1000000000
};

float numberOfFiles(float fileSize, string unitFileSize, float capacityInGig) {
    int b = static_cast<int>(unitSize::B);
    int kb = static_cast<int>(unitSize::KB);
    int mb = static_cast<int>(unitSize::MB);
    int gb = static_cast<int>(unitSize::GB);

    int numFiles = 0;

    if (unitFileSize == "B")
    {
        // cout << "Unit Size: B" << endl;
        // cout << "Capacity: " << (capacityInGig * gb) << endl;
        // cout << "File Size in Bits: " << (fileSize * b) << endl;
        numFiles = (capacityInGig * gb) / (fileSize * b);
    } else if (unitFileSize == "KB")
    {
        // cout << "Unit Size: KB" << endl;
        // cout << "Capacity: " << (capacityInGig * gb) << endl;
        // cout << "File Size in Bits: " << (fileSize * kb) << endl;
        numFiles = (capacityInGig * gb) / (fileSize * kb);
    } else {
        // cout << "Unit Size: MB" << endl;
        // cout << "Capacity: " << (capacityInGig * gb) << endl;
        // cout << "File Size in Bits: " << (fileSize * mb) << endl;
        numFiles = (capacityInGig * gb) / (fileSize * mb);
    }
    
    // cout << numFiles << endl;

    return numFiles;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(numberOfFiles(500, "KB", 1) == 2000);
    check(numberOfFiles(50000, "B", 1) == 20000);
    check(numberOfFiles(5, "MB", 1) == 200);
    check(numberOfFiles(4096, "B", 1.5) == 366210);
    check(numberOfFiles(220.5, "KB", 100) == 453514);
    check(numberOfFiles(4.5, "MB", 750) == 166666);
}