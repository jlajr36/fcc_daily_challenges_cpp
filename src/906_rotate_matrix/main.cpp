#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> matrix) {
    int n = matrix.size();
    // Transpose
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(rotate({{1}}) == vector<vector<int>>{{1}});
    check(rotate({{1, 2}, {3, 4}})
        == vector<vector<int>>{{3, 1}, {4, 2}});
    check(rotate({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}})
        == vector<vector<int>>{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}});
    check(rotate({{0, 1, 0}, {1, 0, 1}, {0, 0, 0}})
        == vector<vector<int>>{{0, 1, 0}, {0, 0, 1}, {0, 1, 0}});
}
