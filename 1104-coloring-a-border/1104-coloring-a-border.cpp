class Solution {
private:
    // direction arrays
    // delta for: up, down, left, right
    int dr[4]{-1, 1, 0 , 0};
    int dc[4]{0, 0, -1 , 1};
public:
    /* 
    * Approach:
    * depth first search
    * 
    * Complexity:
    * Time Complexity : O(N) => O(N + E) , N = m x n, E = 4N => O(5N)
    * Space Complexity : O(N)
    */
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) 
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int oldColor = grid[row][col];
        dfs(grid, row, col, color, oldColor, visited);
        return grid;
    }
    
    bool dfs(vector<vector<int>>& grid, int r, int c, int color, int oldColor, vector<vector<bool>>& visited)
    {
        if(!isValid(r, c ,grid) || (grid[r][c] != oldColor && !visited[r][c]))
            return 1;
        
        if(visited[r][c])
            return 0;
        
        visited[r][c] = 1;
        bool isBorder{};
        
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            isBorder = dfs(grid, nr, nc, color, oldColor, visited);
            if(isBorder)
                grid[r][c] = color;
        }
        return 0;
    }
    
    // return true if this position INSIDE the 2D matrix
    bool isValid(int nr, int nc, vector<vector<int>>& grid)
    {
        if(nr < 0 || nr >= (int)grid.size() || nc < 0 || nc >= (int)grid[0].size())
            return false;
        return true;
    }
};