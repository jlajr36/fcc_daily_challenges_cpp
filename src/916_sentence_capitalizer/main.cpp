#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string capitalize(string paragraph) {
    string result = paragraph;
    bool capitalizeNext = true;

    for (size_t i = 0; i < result.size(); ++i) {
        if (capitalizeNext && isalpha(result[i])) {
            result[i] = toupper(result[i]);
            capitalizeNext = false;
        }
        if (result[i] == '.' || result[i] == '!' || result[i] == '?') {
            capitalizeNext = true;
        }
    }

    return result;
}

void check(bool status) {
    cout << (status ? "PASS" : "FAIL") << endl;
}

int main() {
    check(capitalize("this is a simple sentence.") == "This is a simple sentence.");
    check(capitalize("hello world. how are you?") == "Hello world. How are you?");
    check(capitalize("i did today's coding challenge... it was fun!!") == "I did today's coding challenge... It was fun!!");
    check(capitalize("crazy!!!strange???unconventional...sentences.") == "Crazy!!!Strange???Unconventional...Sentences.");
    check(capitalize("there's a space before this period . why is there a space before that period ?") == "There's a space before this period . Why is there a space before that period ?");
}