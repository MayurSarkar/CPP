#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int st = 0;
        int e = s.size() - 1;
        while (st <= e) {
            if (!isalnum(s[st])) {
                st++;
            } else if (!isalnum(s[e])) {
                e--;
            } else if (tolower(s[st]) != tolower(s[e]))
                return false;
            else {
                st++;
                e--;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (solution.isPalindrome(input)) {
        std::cout << "The input string is a palindrome." << std::endl;
    } else {
        std::cout << "The input string is not a palindrome." << std::endl;
    }

    return 0;
}
