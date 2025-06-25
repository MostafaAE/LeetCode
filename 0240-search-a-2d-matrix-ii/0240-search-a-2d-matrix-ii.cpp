/*
 * Approach:
 * Start from the top-right corner of the matrix.
 * - If the current value is equal to the target, return true.
 * - If the current value is greater than the target, move left.
 * - If the current value is less than the target, move down.
 * 
 * This works because:
 * - Each row is sorted in increasing order (left to right)
 * - Each column is sorted in increasing order (top to bottom)
 *
 * Time Complexity : O(m + n), where m is the number of rows and n is the number of columns
 * Space Complexity: O(1), no extra space used
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        
        int row = 0, col = n - 1;

        while (row < m && col >= 0)
        {
            if (matrix[row][col] == target)
                return true;
            else if (target < matrix[row][col])
                --col;
            else
                ++row;
        }

        return false;
    }
};