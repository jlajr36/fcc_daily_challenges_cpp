#include <iostream>
#include <string>

using namespace std;

string decode(string msg, int shift) {
    string out = "";
    for (char& c : msg) {
        if (c >= 'A' && c <= 'Z') {
            int pos = (c - 'A' - shift) % 26;
            if (pos < 0) pos += 26;               // fix negative remainder
            out += static_cast<char>(pos + 'A');
        } else if (c >= 'a' && c <= 'z') {
            int pos = (c - 'a' - shift) % 26;
            if (pos < 0) pos += 26;               // fix negative remainder
            out += static_cast<char>(pos + 'a');
        } else {
            out += c;
        }
    }
    return out;
}

int main() {
    cout << decode("Xlmw mw e wigvix qiwweki.", 4)   << '\n'; // This is a secret message.
    cout << decode("Byffi Qilfx!", 20)               << '\n'; // Hello World!
    cout << decode("Zqd xnt njzx?", -1)              << '\n'; // Are you okay?
    cout << decode("oannLxmnLjvy", 9)                << '\n'; // freeCodeCamp
    return 0;
}