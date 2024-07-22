#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i])) {
                if (std::abs(i - m[nums[i]]) <= k)
                    return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1,2,3,1}; // Replace with your desired input array
    int k = 3; // Replace with your desired value of 'k'

    bool hasNearbyDuplicate = solution.containsNearbyDuplicate(nums, k);

    if (hasNearbyDuplicate) {
        std::cout << "There is a nearby duplicate element within distance " << k << std::endl;
    } else {
        std::cout << "No nearby duplicate element within distance " << k << std::endl;
    }

    return 0;
}
