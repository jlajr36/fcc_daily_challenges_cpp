#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

template <typename K, typename V>
void printUnorderedMap(const unordered_map<K, V>& umap) {
    for (const auto& [key, value] : umap) {
        cout << key << ": " << value << "\n";
    }
}

vector<int> find_duplicates(vector<int> nums) {
    unordered_map<int, int> map;
    for (int num : nums) {
        map[num] += 1;
    }
    vector<int> duplicates;
    for (auto& [num, count] : map) {
        if (count > 1) {
            duplicates.push_back(num);
        }
    }
    sort(duplicates.begin(), duplicates.end());
    return duplicates;
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(find_duplicates({1, 2, 3, 4, 5}) == vector<int>{});
    check(find_duplicates({1, 2, 3, 4, 1, 2}) == vector<int>{1, 2});
    check(find_duplicates({2, 34, 0, 1, -6, 23, 5, 3, 2, 5, 67, -6, 23, 2, 43, 2, 12, 0, 2, 4, 4}) ==
          vector<int>{-6, 0, 2, 4, 5, 23});
}
