#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the resulting array by performing XOR operation on consecutive elements of 'pref'
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size());
        arr[0] = pref[0];  // The first element of 'arr' is the same as the first element of 'pref'

        // Iterate through 'pref' to calculate the elements of 'arr'
        for (int i = 1; i < pref.size(); i++) {
            // Perform XOR operation on the previous element of 'pref' and the current element
            arr[i] = pref[i - 1] ^ pref[i];
        }
        return arr;  // Return the resulting array 'arr'
    }
};

int main() {
    Solution solution;
    
    vector<int> pref = {5,2,0,3,1};

    // Call the 'findArray' function to compute the resulting array
    vector<int> result = solution.findArray(pref);

    cout << "Resulting array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
