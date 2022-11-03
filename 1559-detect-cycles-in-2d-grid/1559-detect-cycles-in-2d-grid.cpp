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
    bool containsCycle(vector<vector<char>>& grid) 
    {
        int rows{(int)grid.size()}, cols{(int)grid[0].size()};
        vector<vector<bool>> visited(rows, vector<bool>(cols,0));
        bool cycle{};
        for(int r = 0 ; r < rows ; r++)
        {
            for(int c = 0 ; c < cols ; c++)
            {
                if(!visited[r][c])
                    cycle = dfs(grid, r, c, visited, r, c);
                
                if(cycle)
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited, int prevRow, int prevCol)
    {
        bool isCycle{0};
        visited[r][c] = 1;
        
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            
            if(isValid(nr, nc, grid) && grid[nr][nc] == grid[prevRow][prevCol] && (nr != prevRow || nc != prevCol))
            {
                if(visited[nr][nc])
                {
                    isCycle = true;
                    break;
                }
                else if(!isCycle)
                    isCycle |= dfs(grid, nr, nc, visited, r, c);
            }
                
        }
        return isCycle;
    }
    
    // return true if this position INSIDE the 2D matrix
    bool isValid(int nr, int nc, vector<vector<char>>& grid)
    {
        if(nr < 0 || nr >= (int)grid.size() || nc < 0 || nc >= (int)grid[0].size())
            return false;
        return true;
    }
};