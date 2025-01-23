class Solution {
public:
    /**
     * Approach:
     * - Use two arrays (`rowCount` and `colCount`) to count the number of servers in each row and column.
     * - First, iterate through the grid to populate these counts.
     * - Then, iterate through the grid again to check each server. A server can communicate if there is 
     *   more than one server in either its row or column.
     * 
     * Complexity:
     * - Time: O(m * n), where m is the number of rows and n is the number of columns in the grid.
     *   - The grid is traversed twice: once for counting servers and once for verifying communication.
     * - Space: O(m + n), for storing row and column counts.
     */
    int countServers(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();

        vector<int> rowCount(m, 0), colCount(n, 0);

        // Count servers in each row and column
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (grid[i][j]) 
                {
                    ++rowCount[i];
                    ++colCount[j];
                }
            }
        }

        int result = 0;

        // Count servers that can communicate
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (grid[i][j] && (rowCount[i] > 1 || colCount[j] > 1)) 
                {
                    ++result;
                }
            }
        }

        return result;
    }
};
