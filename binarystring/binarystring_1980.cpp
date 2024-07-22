#include <iostream>
#include <vector>
#include <unordered_set>
#include <bitset>

using namespace std;

class Solution {
public:
    // Approach 1: Brute Force
    string callbrute(vector<string>& nums) {
        unordered_set<int> st;
        for (auto i : nums) {
            st.insert(stoi(i, 0, 2)); // Convert binary string to decimal and insert in set
        }
        int n = nums.size();
        string answer;
        // Find the decimal number which is not present in the set
        for (int i = 0; i <= n; i++) {
            if (st.find(i) == st.end()) {
                answer = bitset<16>(i).to_string(); // Convert decimal to binary string
                return answer.substr(16 - n, n); // Trim to the needed length
            }
        }
        return "";
    }

    // Approach 2: Recursion
    void recursion(unordered_set<string>& st, string ans, int n, string& str) {
        if (ans.size() >= n) {
            return;
        }
        if (st.find(ans) == st.end() and ans.size() == (n - 1)) {
            str = ans;
            return;
        }
        st.insert(ans);
        ans.push_back('0');
        recursion(st, ans, n, str);
        ans.pop_back();
        ans.push_back('1');
        recursion(st, ans, n, str);
        ans.pop_back();
    }

    string callbetter(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        string ans = "";
        string str;
        st.insert(ans); // Pushing an empty string into the set
        recursion(st, ans, nums.size() + 1, str);
        return str;
    }

    // Approach 3: Cantor's Diagonal Method
     string calloptimal(vector<string>& nums) {
        int n = nums.size();
        string answer;
        for (int i = 0; i < n; i++) {
            answer += (nums[i][i] == '0') ? '1' : '0'; // Flip the diagonal bit
        }
        return answer;
    }

    // Main function to select the approach
    string findDifferentBinaryString(vector<string>& nums) {
        // Uncomment one of the following lines based on the desired approach:

        // return callbrute(nums); // Brute force approach
        // return callbetter(nums); // Recursive approach
        return calloptimal(nums); // Cantor's Diagonal Method
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<string> binaryStrings = {"00", "01", "10"};
    string result = solution.findDifferentBinaryString(binaryStrings);

    cout << "Result: " << result << endl;

    return 0;
}
