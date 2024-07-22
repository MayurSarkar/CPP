#include <iostream>
#include <vector>

class Solution {
public:
    int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right) {
        int t = 0;
        for (auto it : left) {
            t = std::max(t, it);
        }
        for (auto it : right) {
            t = std::max(t, n - it);
        }
        return t;
    }
};

int main() {
    Solution solution;
    int n = 10; // Replace with your desired value of 'n'
    std::vector<int> left = {2, 4, 6}; // Replace with your desired values for 'left'
    std::vector<int> right = {3, 7, 9}; // Replace with your desired values for 'right'

    int lastMoment = solution.getLastMoment(n, left, right);
    std::cout << "Last moment: " << lastMoment << std::endl;

    return 0;
}
