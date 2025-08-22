class Solution {
public:
    /*
    * Approach:
    * - Iterate over the grid, maintaining the minimum and maximum indecies for rows and columns containing 1.
    * - We can get the total rows count by subtracting the min row index from the max row index.
    * - We can get the total columns count by subtracting the min column index from the max column index.
    * - The minimum possible area will be the total rows count multiplied by the total columns count.
    *
    * Time Complexity: O(m * n), where m is the number of rows, n is the number of columns
    * Space Complexity: O(1)  
    */
    int minimumArea(vector<vector<int>>& grid) 
    {
        int minRow = INT_MAX, maxRow = INT_MIN;
        int minCol = INT_MAX, maxCol = INT_MIN;

        int rows = grid.size(), cols = grid[0].size();
        for(int r = 0 ; r < rows ; ++r)
        {
            for(int c = 0 ; c < cols ; ++c)
            {
                if(grid[r][c])
                {
                    minRow = min(minRow, r);
                    maxRow = max(maxRow, r);
                    minCol = min(minCol, c);
                    maxCol = max(maxCol, c);
                }
            }
        }

        int rowsCount = maxRow - minRow + 1;
        int colsCount = maxCol - minCol + 1; 
        return rowsCount * colsCount;
    }
};