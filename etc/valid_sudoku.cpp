#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create three 2D vectors to track the presence of numbers in rows, columns, and subgrids.
        vector<vector<bool>> row(9, vector<bool>(9, false));  // To track numbers in rows
        vector<vector<bool>> col(9, vector<bool>(9, false));  // To track numbers in columns
        vector<vector<bool>> sub(9, vector<bool>(9, false));  // To track numbers in 3x3 subgrids

        // Iterate through each cell in the Sudoku board (9x9 grid)
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                
                // Skip empty cells denoted by '.'
                if (c == '.') continue;

                // Calculate the numeric value of the character (e.g., '5' becomes 4)
                int num = c - '0' - 1;

                // Calculate the index of the subgrid (0-8) to which the cell belongs
                int k = i / 3 * 3 + j / 3;

                // Check if the number 'num' is already present in the same row, column, or subgrid.
                if (row[i][num] || col[j][num] || sub[k][num]) {
                    return false;  // Return false if the Sudoku board is invalid.
                }

                // Mark the number 'num' as seen in the current row, column, and subgrid.
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
            }
        }

        // If no violations were found, return true, indicating that the Sudoku board is valid.
        return true;
    }
};

int main() {
    Solution solution;
    
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    bool result = solution.isValidSudoku(board);

    if (result) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}
