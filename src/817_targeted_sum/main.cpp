#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> find_target(vector<int> nums, int target) {
    unordered_map<int, int> targets;

    for (size_t i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        auto it = targets.find(diff);

        if (it != targets.end()){
            return {it->second, static_cast<int>(i)};
        }

        targets[nums[i]] = static_cast<int>(i);
    }
    return {};
}

int main() {
    //vector<int> points = find_target({2, 7, 11, 15}, 9);        //[0, 1]
    //vector<int> points = find_target({3, 2, 4, 5}, 6);            //[1, 2]
    vector<int> points = find_target({1, 3, 5, 6, 7, 8}, 15);   //[4, 5]
    //vector<int> points = find_target({1, 3, 5, 7}, 14);         //[]
    cout << points[0] << ", " << points[1];
    return 0;
}