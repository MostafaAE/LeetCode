class Solution {
private:
    // direction arrays
    // delta for: up, down, left, right
    int dr[4]{-1, 1, 0 , 0};
    int dc[4]{0, 0, -1 , 1};
    bool isCycle{};
public:
    /* 
    * Approach:
    * depth first search
    * 
    * Complexity:
    * Time Complexity : O(N) => O(N + E) , N = rows x cols, E = 4N => O(5N)
    * Space Complexity : O(N)
    */
    bool containsCycle(vector<vector<char>>& grid) 
    {
        int rows{(int)grid.size()}, cols{(int)grid[0].size()};
        vector<vector<bool>> visited(rows, vector<bool>(cols,0));
        
        for(int r = 0 ; r < rows ; r++)
        {
            for(int c = 0 ; c < cols ; c++)
            {
                if(!visited[r][c])
                    dfs(grid, r, c, visited, r, c);
                
                if(isCycle)
                    return true;
            }
        }
        return false;
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited, int prevRow, int prevCol)
    {
        if(!isValid(r, c, grid) || grid[r][c] != grid[prevRow][prevCol] || isCycle)
            return;

        if(visited[r][c])
        {
            isCycle = true;
            return;
        }
        
        visited[r][c] = 1;
        
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            
            if(nr == prevRow && nc == prevCol)
                continue;
            
            dfs(grid, nr, nc, visited, r, c);
        }
    }
    
    // return true if this position INSIDE the 2D matrix
    bool isValid(int nr, int nc, vector<vector<char>>& grid)
    {
        if(nr < 0 || nr >= (int)grid.size() || nc < 0 || nc >= (int)grid[0].size())
            return false;
        return true;
    }
};