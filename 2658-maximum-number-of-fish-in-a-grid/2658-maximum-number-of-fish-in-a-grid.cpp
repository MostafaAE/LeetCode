class Solution {
private:
    // Directions for moving up, down, left, and right
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

public:
    /**
     * Approach:
     * - Traverse every cell in the grid.
     * - Use DFS to calculate the total fish count for each connected component.
     * - Update the result with the maximum fish count found.
     * 
     * Complexity:
     * - Time: O(m * n), where m is the number of rows and n is the number of columns. 
     *         Each cell is visited once in the worst case.
     * - Space: O(m * n), due to the recursion stack in DFS.
     */
    int findMaxFish(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        int result = 0;

        // Traverse the grid
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                // If the cell has fish (value > 0), start a DFS
                if (grid[i][j] > 0) 
                {
                    result = max(result, dfs(i, j, grid));
                }
            }
        }

        return result;
    }

private:

    //Performs a DFS to collect fish in a connected component.
    int dfs(int row, int col, vector<vector<int>>& grid) 
    {
        // Collect fish in the current cell
        int count = grid[row][col];

        // Mark the cell as visited by setting its value to 0
        grid[row][col] = 0;

        // Explore all 4 directions
        for (int d = 0; d < 4; ++d) 
        {
            int nr = row + dr[d], nc = col + dc[d];
            
            // Check if the neighboring cell is valid and contains fish
            if (nr >= 0 && nr < grid.size() && nc >= 0 &&
                nc < grid[0].size() && grid[nr][nc] > 0) 
            {
                count += dfs(nr, nc, grid);
            }
        }

        return count;
    }
};
