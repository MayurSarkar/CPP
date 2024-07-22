#include <iostream>
#include <string>

class Solution
{
public:
    std::string answer = "";

    void expand(std::string &s, int left, int right)
    {
        while (left >= 0 && right < s.size())
        {
            if (s[left] != s[right])
                break;
            left--, right++;
        }
        if (answer.size() < right - left)
            answer = s.substr(left + 1, right - left - 1);
    }

    std::string longestPalindrome(std::string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            expand(s, i, i);
            expand(s, i, i + 1);
        }
        return answer;
    }
};

int main()
{
    Solution solution;
    std::string input = "babad"; // Replace with your input string
    std::string result = solution.longestPalindrome(input);
    std::cout << "Longest Palindromic Substring: " << result << std::endl;
    return 0;
}
