class Solution {
private:
    // Arrays to represent the four directions: up, down, left, right
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1, 1};
public:
    /* 
    * Approach:
    * - Depth-First Search with Backtracking
    * - Start from each cell with non-zero gold and perform a Depth-First Search (DFS) with backtracking to explore all possible paths.
    * - Keep track of the maximum amount of gold collected during the DFS traversal.
    *
    * Complexity:
    * - Time Complexity: O(m * n * 4^k), where m and n are the dimensions of the grid, and k is the number of cells with gold.
    *                    For each cell with gold, we potentially explore four directions (up, down, left, right) in the DFS,
    *                    and the maximum depth of the DFS traversal can be up to k.
    * - Space Complexity: O(k), due to the recursive stack space used by the DFS algorithm.
    */
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        int maxGold{};
        
        for(int r = 0 ; r < grid.size() ; ++r)
            for(int c = 0 ; c < grid[0].size() ; ++c)
                if(grid[r][c]) // If the current cell contains gold
                    maxGold = max(maxGold, dfs(grid, r, c));
        
        return maxGold; 
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        int val = grid[r][c];
        grid[r][c] = 0;
        
        int maxGold{};
        for(int d = 0 ; d < 4 ; ++d)
        {
            int nr = r + dr[d], nc = c + dc[d];
            // Check if the neighboring cell is valid and contains gold
            if(isValid(grid, nr, nc) && grid[nr][nc]) 
                maxGold = max(maxGold, dfs(grid, nr, nc));
        }
        
        grid[r][c] = val;
        return maxGold + val;
    }
    
    bool isValid(vector<vector<int>>& grid, int r, int c)
    {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
            return false;
        return true;
    }
};