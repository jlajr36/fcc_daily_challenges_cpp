#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/* Return a numeric value for a character:
   - 'a'‑'z' → 1‑26
   - 'A'‑'Z' → 27‑52
   - everything else → its ASCII code */
int score(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;          // 1‑26
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 27;         // 27‑52
    } else {
        return static_cast<int>(c); // ASCII value
    }
}

/* Compare two strings character‑by‑character.
   Returns the appropriate battle result string. */
string battle(const string& me, const string& them) {
    // Length check – the longer side “retreats”
    if (me.length() > them.length()) {
        return "Opponent retreated";
    }
    if (me.length() < them.length()) {
        return "We retreated";
    }

    // Same length – compare each character
    int h_w = 0;          // wins for “me”
    int a_w = 0;          // wins for “them”

    for (size_t i = 0; i < me.size(); ++i) {
        int s_me   = score(me[i]);
        int s_them = score(them[i]);

        if (s_me > s_them) {
            ++h_w;
        } else if (s_me < s_them) {
            ++a_w;
        }
        // equal scores → no point awarded
    }

    if (h_w > a_w)  return "We won";
    if (h_w < a_w)  return "We lost";
    return "It was a tie";
}

/* Helper to print PASS/FAIL for a test condition */
void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(battle("Hello", "World") == "We lost");
    check(battle("pizza", "salad") == "We won");
    check(battle("C@T5", "D0G$") == "We won");
    check(battle("kn!ght", "orc") == "Opponent retreated");
    check(battle("PC", "Mac") == "We retreated");
    check(battle("Wizards", "Dragons") == "It was a tie");
    check(battle("Mr. Smith", "Dr. Jones") == "It was a tie");
    return 0;
}