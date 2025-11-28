#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>   // for std::round

std::string padTwoZeros(int value) {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << value;
    return oss.str();
}

std::string milePace(double miles, const std::string& timeStr) {
    std::size_t pos = timeStr.find(':');
    if (pos == std::string::npos) return "";   // invalid format

    int minutes = std::stoi(timeStr.substr(0, pos));
    int seconds = std::stoi(timeStr.substr(pos + 1));

    int totalTime = minutes * 60 + seconds;    // total seconds
    int timeSplit = static_cast<int>(std::round(totalTime / miles)); // seconds per mile

    int paceMinute = timeSplit / 60;
    int paceSecond = timeSplit % 60;
    return padTwoZeros(paceMinute) + ":" + padTwoZeros(paceSecond);
}

int main() {
    std::cout << milePace(3,    "24:00") << '\n'; // 08:00
    std::cout << milePace(1,    "06:45") << '\n'; // 06:45
    std::cout << milePace(2,    "07:00") << '\n'; // 03:30
    std::cout << milePace(26.2, "120:35") << '\n'; // 04:36 (rounded)
}