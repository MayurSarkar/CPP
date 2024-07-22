#include <string>
#include <iostream>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string w; // Temporary string to hold characters of a word
        std::string a; // Resultant string to store the final output
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                w.push_back(s[i]);
                if ((i > 0 && s[i - 1] == ' ') || (i == 0)) {
                    for (int j = w.length() - 1; j >= 0; j--) {
                        a.push_back(w[j]);
                    }
                    a.push_back(' ');
                    w.clear();
                }
            }
        }
        if (!a.empty() && a.back() == ' ') {
            a.pop_back();
        }
        return a;
    }
};

int main() {
    Solution solution;
    std::string input = "  the sky is blue";
    std::string output = solution.reverseWords(input);
    std::cout << "Reversed words: " << output <<"."<< std::endl;
    return 0;
}
