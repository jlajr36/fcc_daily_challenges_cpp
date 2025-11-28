#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_laptop_cost(vector<int> costs, int budget) {
    sort(costs.begin(), costs.end(), greater<int>());
    auto last = std::unique(costs.begin(), costs.end());
    costs.erase(last, costs.end());
    if (costs[0] <= budget && costs[1] <= budget) {
        return costs[1];
    }
    for (int cost : costs) {
        if (cost <= budget) {
            return cost;
        }
    }
    return 0;
}

void check(bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
}

int main() {
    check(get_laptop_cost({1500, 2000, 1800, 1400}, 1900) == 1800);
    check(get_laptop_cost({1500, 2000, 2000, 1800, 1400}, 1900) == 1800);
    check(get_laptop_cost({2099, 1599, 1899, 1499}, 2200) == 1899);
    check(get_laptop_cost({2099, 1599, 1899, 1499}, 1000) == 0);
    check(get_laptop_cost({1200, 1500, 1600, 1800, 1400, 2000}, 1450) == 1400);
}