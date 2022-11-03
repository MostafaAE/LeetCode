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
    * Time Complexity : O(N) => O(N + E) , N = rows x cols, E = 4N => O(5N)
    * Space Complexity : O(N)
    */
    int closedIsland(vector<vector<int>>& grid) 
    {
        int rows{(int)grid.size()}, cols{(int)grid[0].size()};
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        int closedIslands{};
        
        for(int r = 1 ; r < rows-1 ; r++)
            for(int c = 1 ; c < cols-1 ; c++)
                if(!grid[r][c] && !visited[r][c])
                    closedIslands += dfs(grid, r, c, visited);
        
        return closedIslands;
    }
    
    bool dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited)
    {   
        bool isClosed{1};
        
        if(!isValid(r, c, grid))
            return false;
        
        if(visited[r][c] || grid[r][c])
            return true;
        
        visited[r][c] = true;
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            isClosed &= dfs(grid, nr, nc, visited);
        }
        return isClosed;
    }
    
    // return true if this position INSIDE the 2D matrix
    bool isValid(int nr, int nc, vector<vector<int>>& grid)
    {
        if(nr < 0 || nr >= (int)grid.size() || nc < 0 || nc >= (int)grid[0].size())
            return false;
        return true;
    }

};