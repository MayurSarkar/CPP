#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // Create a map to store the counts of words in the 'words' vector
        unordered_map<string, int> cnt;
        for (auto& w : words) {
            ++cnt[w];
        }
        
        int m = s.size();        // Length of the input string
        int n = words.size();    // Number of words to search for
        int k = words[0].size(); // Length of each word

        // Vector to store the starting indices of valid substrings
        vector<int> ans;

        // Iterate through different starting positions within each word
        for (int i = 0; i < k; ++i) {
            // Create a map to keep track of words encountered in the sliding window
            unordered_map<string, int> cnt1;
            int l = i, r = i; // Left and right pointers of the sliding window
            int t = 0;        // Count of words encountered in the window

            // Continue while there are enough characters remaining in 's'
            while (r + k <= m) {
                // Extract the next word of length 'k' from 's'
                string w = s.substr(r, k);
                cout<<w<<endl;
                r += k;
                cout<<"r"<<r<<"k"<<k<<endl;

                // If 'w' is not in the 'cnt' map, skip this portion
                if (!cnt.count(w)) {
                    cnt1.clear();
                    l = r;
                    t = 0;
                    continue;
                }

                // Update the count of 'w' in the 'cnt1' map and increment 't'
                ++cnt1[w];
                ++t;
                cout<<"t"<<t<<"cnt1"<<endl;

                // Remove words from the left side of the window until the count of 'w' is within the allowed limit
                while (cnt1[w] > cnt[w]) {
                    string remove = s.substr(l, k);
                    l += k;
                    --cnt1[remove];
                    --t;
                }

                // If all required words have been found in the window, add 'l' to 'ans'
                if (t == n) {
                    ans.push_back(l);
                }
            }
        }
        // Return the vector containing the starting indices of valid substrings
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> result = solution.findSubstring(s, words);

    cout << "Starting indices of valid substrings: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
