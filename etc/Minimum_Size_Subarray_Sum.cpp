#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = -1;  // Initialize left and right pointers.
        int sum = 0;        // Initialize the current sum.
        int minLength = nums.size();  // Initialize the minimum length.

        while (l < nums.size()) {
            cout << "l:" << l << endl;
            cout << "r:" << r << endl;

            // Check if we can extend the window to the right.
            if (r + 1 < nums.size() && sum < target) {
                sum += nums[++r];  // Extend the window to the right by including the next element.
            } else {
                sum -= nums[l++];  // Shrink the window from the left by excluding the leftmost element.
            }

            // Check if the current subarray sum is greater than or equal to the target.
            if (sum >= target) {
                minLength = min(minLength, r - l + 1);  // Update the minimum length.
            }
        }

        // If minLength is still the initial value, there's no subarray with a sum at least the target.
        return minLength == nums.size()  ? 0 : minLength;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int result = solution.minSubArrayLen(target, nums);

    cout << "Minimum subarray length with a sum of at least " << target << ": " << result << endl;

    return 0;
}
