/*
 * Approach:
 * We are given a binary grid and need to count the number of right-angled triangles 
 * where the right angle lies at a cell (r, c) with value 1.
 * 
 * A valid triangle requires at least one other 1 in the same row and one in the same column.
 * 
 * Steps:
 * 1. Count how many 1s exist in each row and column using `xFreq` and `yFreq`.
 * 2. For each cell (r, c) where grid[r][c] == 1:
 *    - We can pair this cell with (xFreq[r] - 1) cells in the same row
 *      and (yFreq[c] - 1) cells in the same column to form valid right-angled triangles.
 *    - Multiply the two to get the number of triangles centered at (r, c).
 * 3. Accumulate the total number of such triangles.
 * 
 * Time Complexity  : O(m * n), where m = number of rows, n = number of columns
 *                    -> One full pass to count, one pass to calculate results.
 * Space Complexity : O(m + n), for the row and column frequency vectors.
 */

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) 
    {
        int rows = grid.size(), cols = grid[0].size();

        // Count of 1s in each row and column
        vector<int> xFreq(rows, 0); 
        vector<int> yFreq(cols, 0); 

        // First pass: count 1s in each row and column
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                xFreq[r] += grid[r][c];
                yFreq[c] += grid[r][c];
            }
        }

        long long result = 0;

        // Second pass: count right-angled triangles centered at (r, c)
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == 1)
                {
                    result += (long long)(xFreq[r] - 1) * (yFreq[c] - 1);
                }
            }
        }

        return result;
    }
};