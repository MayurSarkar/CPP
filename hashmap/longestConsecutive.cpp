#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        int maxCount = 0; // Initialize a variable to store the maximum consecutive sequence length.
        std::unordered_map<int, bool> map{}; // Create an unordered map to track the presence of each element.

        // Step 1: Store the presence of each element in the map.
        for (auto& num : nums) {
            map[num] = true;
        }

        // Step 2: Iterate through the nums vector to find the longest consecutive sequence.
        for (auto& num : nums) {
            int count = 0; // Initialize a variable to count the consecutive sequence length.

            // Step 3a: Check if the element is already processed. If so, continue to the next element.
            if (!map[num]) continue;

            // Step 3b: If the element is not processed and the previous element is not present in the map,
            // start a sequence and count consecutive elements.
            if (map[num] && !map[num - 1]) {
                int start_value = num;
                count = 1;
                while (map[++start_value]) {
                    count++;
                    map[start_value] = false; // Mark the element as processed.
                }
            }

            // Step 3c: Update maxCount if the current sequence is longer.
            if (count > maxCount) maxCount = count;
        }

        // Step 4: Return the maximum consecutive sequence length.
        return maxCount;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {100, 4, 200, 1, 3, 2}; // Replace with your desired input vector

    // Find the length of the longest consecutive subsequence.
    int longestConsecutiveLength = solution.longestConsecutive(nums);
    std::cout << "Longest consecutive subsequence length: " << longestConsecutiveLength << std::endl;

    return 0;
}
