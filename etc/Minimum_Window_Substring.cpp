#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int need[128]{};    // An array to keep track of the characters needed from 't'
        int window[128]{};  // An array to keep track of the characters in the current window
        int m = s.size();   // Length of string 's'
        int n = t.size();   // Length of string 't'

        // Count the characters needed from 't'
        for (char& c : t) {
            ++need[c];
        }

        int cnt = 0;  // Counter for characters matched with 't'
        int j = 0;    // Left pointer of the sliding window
        int k = -1;   // Start index of the minimum window substring
        int mi = 1 << 30;  // Initialize the minimum window length with a large value

        for (int i = 0; i < m; ++i) {
            // Expand the window and update the 'window' array
            ++window[s[i]];

            // If the character at position 'i' is needed from 't', increment the 'cnt'
            if (need[s[i]] >= window[s[i]]) {
                ++cnt;
            }

            // Check if all characters from 't' are matched
            while (cnt == n) {
                // Update the minimum window length and start index
                if (i - j + 1 < mi) {
                    mi = i - j + 1;
                    k = j;
                }

                // Check if the character at position 'j' is needed from 't'
                if (need[s[j]] >= window[s[j]]) {
                    // Decrement the 'cnt' since this character is no longer in the window
                    --cnt;
                }

                // Contract the window by moving the left pointer
                --window[s[j++]];
            }
        }

        // Return the minimum window substring, or an empty string if no valid window is found
        return k < 0 ? "" : s.substr(k, mi);
    }
};

int main() {
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = solution.minWindow(s, t);

    cout << "Minimum window substring: " << result << endl;

    return 0;
}
