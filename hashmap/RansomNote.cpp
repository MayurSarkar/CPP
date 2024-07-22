#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int c1[26] = {0};
        int c2[26] = {0};

        for (char ch : ransomNote) {
            c1[ch - 'a']++;
        }

        for (char ch : magazine) {
            c2[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (c1[i] > c2[i])
                return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Example 1: Can construct "a" from "b"
    string ransomNote1 = "a";
    string magazine1 = "b";
    bool result1 = solution.canConstruct(ransomNote1, magazine1);
    cout << "Can construct ransomNote1 from magazine1: " << (result1 ? "Yes" : "No") << endl;

    // Example 2: Can construct "aa" from "aab"
    string ransomNote2 = "aa";
    string magazine2 = "aab";
    bool result2 = solution.canConstruct(ransomNote2, magazine2);
    cout << "Can construct ransomNote2 from magazine2: " << (result2 ? "Yes" : "No") << endl;

    return 0;
}
