#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p=0,count=1,pos=1;
        for(int i=1;i<n;i++)
        {
            if(nums[p]!=nums[i])
            {
                count =1;
                nums[pos] = nums[i];
                p=i;
                pos++;
            }
            else
            {
                while(count<2)
                {
                    count++;
                    nums[pos] = nums[i];
                    pos++;
                }
                count++;
            }
        }
        return pos;
    }
};

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    Solution solution;
    int pos = solution.removeDuplicates(nums);
    cout<<pos;
}