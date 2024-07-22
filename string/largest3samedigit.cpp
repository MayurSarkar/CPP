#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char r = 0;

        // Iterate through the characters of 'num'
        for (int i = 1; i < num.length() - 1; i++) {
            // Check if three consecutive characters are equal
            if (num[i - 1] == num[i] && num[i] == num[i + 1]) {
                // Update 'r' with the maximum value of the consecutive characters
                r = max(r, num[i]);
            }
        }

        // If 'r' is still 0, no three consecutive equal characters were found
        if (r == 0)
            return "";

        cout<<"r: "<<r;
        // Return a string of length 3 with the character 'r'
        return string(3, r);
    }
};

int main() {
    // Example usage
    Solution solution;
    string result = solution.largestGoodInteger("122333");
    cout<< "Result: " << result << endl;

    return 0;
}
