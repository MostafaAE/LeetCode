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
    * Time Complexity : O(N) => O(N + E) , N = row x col, E = 4N => O(5N)
    * Space Complexity : O(N)
    */
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int rows{(int)grid.size()}, cols{(int)grid[0].size()};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int perimeter{};
        
        for(int r = 0 ; r < rows ; r++)
            for(int c = 0 ; c < cols ; c++)
                if(!visited[r][c] && grid[r][c])
                    perimeter = dfs(grid, r, c, visited);
        
        return perimeter;
        
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited)
    {
        int perimeter{};
        
        if(!isValid(r, c, grid) || !grid[r][c])
            return 1;
        
        if(visited[r][c])
            return 0;
        
        visited[r][c] = true;
        
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = r + dr[d] , nc = c + dc[d];
            perimeter += dfs(grid, nr, nc, visited);   
        }
        
        return perimeter;
    }
    
    // return true if this position INSIDE the 2D matrix
    bool isValid(int nr, int nc, vector<vector<int>>& grid)
    {
        if(nr < 0 || nr >= (int)grid.size() || nc < 0 || nc >= (int)grid[0].size())
            return false;
        return true;
    }
};