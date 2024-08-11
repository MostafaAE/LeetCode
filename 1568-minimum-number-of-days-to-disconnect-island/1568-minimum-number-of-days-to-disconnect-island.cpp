class Solution {
private:
    int dr[4]{-1, 1, 0, 0};  // Directions for row movement (up, down, left, right)
    int dc[4]{0, 0, -1, 1};  // Directions for column movement (up, down, left, right)

public:
    /**
     * Approach:
     * - The problem is to find the minimum number of days required to disconnect a grid of land cells.
     * - The strategy involves three main steps:
     *   1. Count the number of islands initially present in the grid. If it is not exactly one, return 0.
     *   2. Attempt to disconnect the grid by removing each land cell one at a time, and check if the grid becomes disconnected (i.e., the number of islands changes). If successful, return 1.
     *   3. If no single removal results in disconnection, return 2 (since removing any two cells must disconnect the grid).
     * 
     * Complexity:
     * - Time Complexity: O((n * m)^2), where `n` and `m` are the number of rows and columns, respectively. The DFS traversal is repeated for each land cell.
     * - Space Complexity: O(n * m), for the visited grid used during DFS.
     */
    int minDays(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // Count initial islands
        int initialIslandCount = countIslands(grid);

        // Already disconnected or no land
        if (initialIslandCount != 1)
            return 0;

        // Try removing each land cell
        for (int row = 0; row < rows; row++) 
        {
            for (int col = 0; col < cols; col++) 
            {
                if (grid[row][col] == 0) continue;  // Skip water

                // Temporarily change to water
                grid[row][col] = 0;
                int newIslandCount = countIslands(grid);

                // Check if disconnected
                if (newIslandCount != 1) return 1;

                // Revert change
                grid[row][col] = 1;
            }
        }

        return 2;
    }
    
    // Count the number of islands in the grid using DFS.
    int countIslands(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islandCount = 0;

        // Iterate through all cells
        for (int row = 0; row < rows; row++) 
        {
            for (int col = 0; col < cols; col++) 
            {
                // Found new island
                if (!visited[row][col] && grid[row][col] == 1) 
                {
                    dfs(grid, row, col, visited);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }

    // DFS to explore all cells of an island.
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) 
    {
        visited[row][col] = true;

        // Check all adjacent cells
        for (int d = 0 ; d < 4 ; d++)
        {
            int nr = row + dr[d], nc = col + dc[d];
            
            // Explore if valid land cell
            if (isValid(grid, nr, nc) && !visited[nr][nc] && grid[row][col] == 1) 
                dfs(grid, nr, nc, visited);
        }
    }

    bool isValid(vector<vector<int>>& grid, int row, int col) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(row < 0 || row >= rows || col < 0 || col >= cols)
            return false;
        return true;
    }
};