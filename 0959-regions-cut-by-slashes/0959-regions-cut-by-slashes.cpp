class Solution {
private:
    int dr[4]{-1, 1, 0, 0};  // Directions for row movement (up, down, left, right)
    int dc[4]{0, 0, -1, 1};  // Directions for column movement (up, down, left, right)

public:
    /**
     * Approach:
     * - Expand the given grid by 3x to handle slashes and backslashes distinctly.
     * - Traverse each cell in the original grid, and depending on whether it contains a '/' or '\', fill in the corresponding diagonal in the expanded grid.
     * - After constructing the expanded grid, perform a DFS to count the number of connected regions.
     * - Each connected component in the expanded grid represents a distinct region.
     *
     * Complexity:
     * - Time Complexity: O(n^2) for expanding the grid, O(n^2) for filling in the slashes, and O(n^2) for DFS.
     *   Overall time complexity is O(n^2).
     * - Space Complexity: O(n^2) for the expanded grid and O(n^2) for the visited array.
     */
    int regionsBySlashes(vector<string>& grid) 
    {
        int n = grid.size();
        
        // Expand the grid by 3x to handle the slashes distinctly
        vector<vector<int>> expandedGrid(n * 3, vector<int>(n * 3, 0));
        
        // Mark the slashes and backslashes on the expanded grid
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] != ' ')
                    cutBySlash(expandedGrid, grid[i][j], i, j);
            }
        }
        
        // Find and count the number of regions using DFS
        return findNumberOfRegions(n * 3, expandedGrid);
    }
    
    // Function to mark slashes ('/' and '\') in the expanded grid
    void cutBySlash(vector<vector<int>>& expandedGrid, char c, int row, int col)
    {
        if(c == '/')
        {
            for(int i = 0; i < 3; ++i)
                expandedGrid[row * 3 + i][col * 3 + 2 - i] = 1;
        }
        else if(c == '\\')
        {
            for(int i = 0; i < 3; ++i)
                expandedGrid[row * 3 + i][col * 3 + i] = 1;
        }
    }
    
    // Function to find the number of connected regions in the expanded grid
    int findNumberOfRegions(int n, vector<vector<int>>& expandedGrid)
    {
        int result{};
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        
        // Traverse the expanded grid and use DFS to count connected regions
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(!visited[i][j] && expandedGrid[i][j] == 0)
                {
                    dfs(i, j, expandedGrid, visited);
                    ++result;
                }
            }
        }
        
        return result;
    }
    
    // Depth-first search to explore the entire connected region
    void dfs(int r, int c, vector<vector<int>>& expandedGrid, vector<vector<bool>>& visited)
    {
        visited[r][c] = true;
        expandedGrid[r][c] = 1;
        
        for(int d = 0; d < 4; ++d)
        {
            int nr = r + dr[d], nc = c + dc[d];
            if(isValid(nr, nc, expandedGrid) && !visited[nr][nc] && expandedGrid[nr][nc] == 0)
                dfs(nr, nc, expandedGrid, visited);
        }
    }

    // Check if the new position is within bounds of the grid
    bool isValid(int nr, int nc, vector<vector<int>>& expandedGrid)
    {
        int n = expandedGrid.size();
        return nr >= 0 && nr < n && nc >= 0 && nc < n;
    }
};
