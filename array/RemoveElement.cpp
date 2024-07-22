#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};

int main()
{
    vector<int> nums = {3,2,2,3};
    int val = 3;

    Solution solution;
    int newLength = solution.removeElement(nums, val);

    cout<<"New Length: "<<newLength<<endl;
    cout<<"Modified Array: ";
    for(int i=0;i<newLength; i++){
        cout<< nums[i] << " ";
    }
}