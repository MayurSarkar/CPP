// #include <iostream>
// #include <vector>

// using namespace std;

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int m = matrix.size();   // Number of rows in the matrix
//         int n = matrix[0].size(); // Number of columns in the matrix

//         // An array 'dirs' to define movement directions: right, down, left, up
//         int dirs[5] = {0, 1, 0, -1, 0};

//         vector<int> ans; // A vector to store the spiral order elements

//         // Loop to traverse the matrix in a spiral order
//         for (int h = m * n, i = 0, j = 0, k = 0; h; --h) {
//             ans.push_back(matrix[i][j]);  // Add the current element to the result
//             matrix[i][j] += 300;          // Mark the visited element with an offset

//             // Calculate the next coordinates (x, y) based on the current direction 'k'
//             int x = i + dirs[k];
//             int y = j + dirs[k + 1];

//             // Check if the next coordinates are out of bounds or if the next element is already visited
//             if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] > 100) {
//                 k = (k + 1) % 4;  // Change the direction (right, down, left, up)
//             }

//             // Update the current coordinates (i, j) based on the current direction 'k'
//             i += dirs[k];
//             j += dirs[k + 1];
//         }

//         // Commented out code to reset the matrix elements to their original values
//         // Uncomment if you want to revert the changes made to the matrix
//         // for (int i = 0; i < m; ++i) {
//         //     for (int j = 0; j < n; ++j) {
//         //         matrix[i][j] -= 300;
//         //     }
//         // }

//         return ans; // Return the spiral order elements
//     }
// };

// int main() {
//     Solution solution;

//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     vector<int> result = solution.spiralOrder(matrix);

//     cout << "Spiral order elements: ";
//     for (int num : result) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }

// /*
// Intuition

// The code is meant to traverse a 2D matrix in a spiral order. Starting from the top-left corner of the matrix, it moves in a clockwise direction, extracting elements as it goes, until it has visited all elements in the matrix.
// Approach

//     Initialize four variables top, left, right, and bottom to represent the boundaries of the submatrix you are currently traversing. Initially, they are set to the outermost boundaries of the matrix.
//     Use a while loop that continues as long as top is less than or equal to bottom and left is less than or equal to right. This ensures that the loop continues until all elements in the matrix are traversed.
//     Inside the loop, there are four for loops:
//         The first loop moves from left to right at the current top row, adding elements to the result vector.
//         The second loop moves from top to bottom at the current right column, adding elements to the result vector.
//         The third loop moves from right to left at the current bottom row, but only if top is still less than or equal to bottom. This avoids duplicate traversal when there's only one row left.
//         The fourth loop moves from bottom to top at the current left column, but only if left is still less than or equal to right. This avoids duplicate traversal when there's only one column left.
//     Adjust the boundary variables (top, left, right, bottom) accordingly as you complete each loop iteration.
//     Continue this process until all elements in the matrix are added to the result vector.
//     Finally, return the result vector containing the elements in spiral order.

// Complexity

//     Time complexity:
//     The code visits each element in the matrix exactly once, so the time complexity is O(n * m), where n is the number of rows and m is the number of columns in the matrix.

//     Space complexity:
//     The space complexity is O(n * m) as well because the result vector contains all the elements in the matrix. In the worst case, it stores all the elements.

// Code

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         if (n == 0) return {};
//         int m = matrix[0].size();
//         int top = 0, left = 0, right = m - 1, bottom = n - 1;
//         vector<int> v;

//         while (top <= bottom && left <= right) {
//             for (int i = left; i <= right; i++) {
//                 v.emplace_back(matrix[top][i]);
//             }
//             top++;
//             for (int i = top; i <= bottom; i++) {
//                 v.emplace_back(matrix[i][right]);
//             }
//             right--;
//             if (top <= bottom) {
//                 for (int i = right; i >= left; i--) {
//                     v.emplace_back(matrix[bottom][i]);
//                 }
//                 bottom--;
//             }
//             if (left <= right) {
//                 for (int i = bottom; i >= top; i--) {
//                     v.emplace_back(matrix[i][left]);
//                 }
//                 left++;
//             }
//         }
//         return v;
//     }
// };
// */
#include <iostream>
 #include <vector>

 using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return {};
        int m = matrix[0].size();
        int top = 0, left = 0, right = m - 1, bottom = n - 1;
        vector<int> v;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                v.emplace_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                v.emplace_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    v.emplace_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    v.emplace_back(matrix[i][left]);
                }
                left++;
            }
        }
        return v;
    }
};
int main() {
     Solution solution;

     vector<vector<int>> matrix = {
         {1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}
     };

     vector<int> result = solution.spiralOrder(matrix);

     cout << "Spiral order elements: ";
     for (int num : result) {
         cout << num << " ";
     }
     cout << endl;

     return 0;
}