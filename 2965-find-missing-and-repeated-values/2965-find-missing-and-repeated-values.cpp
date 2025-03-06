class Solution {
public:
    /**
     * Approach:
     * - The grid contains numbers from 1 to n^2, but one number is missing, and another is repeated.
     * - We use Cycle Sort to place each number in its correct position:
     *   - The correct position for a number `val` is determined by:
     *     - `x = (val - 1) / n` (row index)
     *     - `y = (val - 1) % n` (column index)
     *   - If a number is already at its correct position, we move on.
     *   - If swapping is required, we swap `grid[i][j]` with `grid[x][y]`.
     *   - If we find a duplicate (i.e., two values at the same position are the same), we record it as `repeated`.
     * - After sorting, we scan the grid to find the missing number.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(n^2)
     *   - We iterate over the entire grid and perform cycle sort, which runs in O(n^2) time for an n×n grid.
     * - Space Complexity: O(1)
     *   - Sorting is done in-place, using only a few extra variables.
     */
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int repeated{-1}, missing{1};

        // Cycle sort on the grid
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                int val = grid[i][j];

                int x = (val - 1) / n;  // Expected row index
                int y = (val - 1) % n;  // Expected column index
                
                // Swap until we place the value in its correct position
                if(i != x || j != y)
                {
                    if(grid[i][j] == grid[x][y]) // Found duplicate
                    {
                        repeated = grid[i][j];
                    }
                    else
                    {
                        swap(grid[i][j], grid[x][y]);
                        --j;  // Recheck the current position after swapping
                    }
                }
            }
        }
        
        // Find the missing value
        int expectedVal = 1;
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j, ++expectedVal)
            {
                if(grid[i][j] != expectedVal)
                {
                    missing = expectedVal;
                    break;
                }
            }
        }

        return {repeated, missing};
    }
};
