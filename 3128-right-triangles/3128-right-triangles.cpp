/*
 * Approach:
 * - The goal is to count the number of right-angled triangles in a grid 
 *   where the right angle is at a point with value 1 (i.e., grid[r][c] == 1).
 * - For a right triangle with a right angle at (r, c), it must have one point in the same row
 *   and one point in the same column (excluding the point itself).
 *
 * - First, count the number of 1s in each row and each column using hash maps: `xFreq` and `yFreq`.
 * - Then, iterate through the grid again:
 *     - For each 1 at (r, c), the number of valid triangles centered at this point is:
 *       (number of other 1s in the same row) * (number of other 1s in the same column)
 *     - That is: (xFreq[r] - 1) * (yFreq[c] - 1)
 *
 * Time Complexity  : O(m * n), where m is the number of rows and n is the number of columns.
 *                    We visit each cell twice: once for counting frequencies, once for computing results.
 * Space Complexity : O(m + n), for storing the frequency of 1s in each row and column.
 */

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) 
    {
        int rows = grid.size(), cols = grid[0].size();
        unordered_map<int, int> xFreq; // row index -> count of 1s
        unordered_map<int, int> yFreq; // col index -> count of 1s

        // First pass: count number of 1s in each row and column
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c])
                {
                    ++xFreq[r];
                    ++yFreq[c];
                }
            }
        }

        long long result = 0;

        // Second pass: for each 1, count triangles with right angle at (r, c)
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c])
                {
                    result += (long long)(xFreq[r] - 1) * (yFreq[c] - 1);
                }
            }
        }

        return result;
    }
};