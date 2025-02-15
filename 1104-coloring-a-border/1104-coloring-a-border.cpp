class Solution {
private:
    // Directions for moving in the grid (up, down, left, right)
    int dr[4]{-1, 1, 0 , 0};
    int dc[4]{0, 0, -1 , 1};

public:
    /**
     * Approach:
     * 1. Use Depth-First Search (DFS) to traverse all connected cells of the same color starting from the given (row, col).
     * 2. For each cell:
     *    - If any neighboring cell is out of bounds or a different color, mark it as a border by changing its color.
     *    - Continue DFS for all valid neighboring cells with the same original color.
     * 3. Use a `visited` 2D vector to track visited cells and avoid revisiting.
     * 4. Return the modified grid with colored borders.
     *
     * Complexity:
     * - Time Complexity: O(m * n), where `m` is the number of rows and `n` is the number of columns.
     *   - In the worst case, we visit every cell once.
     * - Space Complexity: O(m * n) for the recursion stack and the `visited` 2D vector.
     **/
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        // Start DFS from the initial (row, col)
        dfs(grid, visited, row, col, grid[row][col], color);

        return grid;
    }
    
private:
    /**
     * DFS helper function to explore the grid and color borders.
     * - `grid`: Reference to the grid.
     * - `visited`: 2D vector to track visited cells.
     * - `row`, `col`: Current cell position.
     * - `originalColor`: The initial color of the connected component.
     * - `color`: The new color for the border.
     **/
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, int originalColor, int color)
    {
        // Mark the current cell as visited
        visited[row][col] = true;

        // Check all 4 directions (up, down, left, right)
        for(int d = 0 ; d < 4 ; ++d)
        {
            int nr = row + dr[d], nc = col + dc[d];
            
            // If neighboring cell is out of bounds or a different color, mark as border
            if(!isValid(nr, nc, grid) || (!visited[nr][nc] && grid[nr][nc] != originalColor))
                grid[row][col] = color;

            // Continue DFS if neighbor is valid, unvisited, and same color
            if(isValid(nr, nc, grid) && !visited[nr][nc] && grid[nr][nc] == originalColor)
            {
                dfs(grid, visited, nr, nc, originalColor, color);
            }
        }
    }
    
    /**
     * Helper function to check if a cell is within grid bounds.
     * - `nr`, `nc`: The next row and column to check.
     * - `grid`: Reference to the grid.
     * Returns true if the cell is within the grid boundaries, false otherwise.
     **/
    bool isValid(int nr, int nc, vector<vector<int>>& grid)
    {
        return (nr >= 0 && nr < (int)grid.size() && nc >= 0 && nc < (int)grid[0].size());
    }
};
