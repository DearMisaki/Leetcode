#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        // Initialize board with empty dots
        vector<string> board(n, string(n, '.'));
        
        // Use boolean arrays for O(1) lookups
        // Columns
        cols = vector<bool>(n, false);
        // Main diagonal: row - col ranges from -(n-1) to (n-1). Shift by +n to make positive. size ~ 2n
        diag1 = vector<bool>(2 * n, false); 
        // Anti diagonal: row + col ranges from 0 to 2n-2. size ~ 2n
        diag2 = vector<bool>(2 * n, false);

        backtrace(board, 0, n);
        return result;
    }

private:
    vector<vector<string>> result;
    vector<bool> cols;
    vector<bool> diag1; // row - col
    vector<bool> diag2; // row + col

    void backtrace(vector<string>& board, int row, int n) {
        // Base Case: If we have placed queens in all rows (0 to n-1)
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            // Calculate diagonal indices
            int d1 = row - col + n; // Shifted to be non-negative
            int d2 = row + col;

            // Check if this position is under attack
            if (!cols[col] && !diag1[d1] && !diag2[d2]) {
                
                // Place Queen
                board[row][col] = 'Q';
                cols[col] = true;
                diag1[d1] = true;
                diag2[d2] = true;

                // Recurse to next row
                backtrace(board, row + 1, n);

                // Backtrack (Remove Queen)
                board[row][col] = '.';
                cols[col] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
        }
    }
};

int main()
{
    Solution().solveNQueens(4);
    return 0;
}