#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int removeDuplicates(vector<int>& nums){
        int k=nums[0];
        int c=1;

        for(int i=1;i<nums.size();i++)
        {
            if(k!=nums[i])
            {    
                nums[c] = nums[i];
                k = nums[i];
                c++;
            }
        }
        return c;
    }
};

int main()
{
    vector<int> nums = {1,1,2};
    Solution solution;
    int l = solution.removeDuplicates(nums);
    cout<<"O/P: "<<l<<endl;
}