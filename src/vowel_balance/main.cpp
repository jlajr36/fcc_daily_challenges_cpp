#include <iostream>
#include <string>
#include <cctype>
#include <array>

bool isBalanced(const std::string& str) {
    const std::string vowels = "aeiouAEIOU";

    std::size_t n = str.size();
    std::size_t mid = n / 2;
    bool even = (n % 2) == 0;
    std::size_t secondStart = even ? mid : mid + 1;

    int leftVowels = 0, rightVowels = 0;

    for (std::size_t i = 0; i < mid; ++i)
        if (vowels.find(str[i]) != std::string::npos) ++leftVowels;

    for (std::size_t i = secondStart; i < n; ++i)
        if (vowels.find(str[i]) != std::string::npos) ++rightVowels;

    return leftVowels == rightVowels;
}

int main() {
    // test strings and the expected result
    std::array<std::pair<std::string, bool>, 7> tests = {{
        {"racecar",               true},
        {"Lorem Ipsum",           true},
        {"Kitty Ipsum",           false},
        {"string",                false},
        {" ",                     true},
        {"abcdefghijklmnopqrstuvwxyz", false},
        {"123A#b!E&*456-o.U",     true}
    }};

    std::cout << std::boolalpha;   // print true/false
    for (const auto& [s, expected] : tests) {
        bool result = isBalanced(s);
        std::cout << '"' << s << "\": " << result
                  << "  ->  " << (result == expected ? "PASS" : "FAIL")
                  << '\n';
    }
    return 0;
}
