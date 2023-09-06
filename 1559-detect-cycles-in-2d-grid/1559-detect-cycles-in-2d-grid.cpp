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
                {
                    dfs(grid, visited, r, c, r, c);
                    if(isCycle)
                        return true;
                }
            }
        }
        return false;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int prevRow, int prevCol)
    {
        visited[r][c] = true;

        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];

            if(isValid(nr, nc, grid) && (nr != prevRow || nc != prevCol) && grid[nr][nc] == grid[r][c])
            {
                if(visited[nr][nc])
                    isCycle = true;
                else 
                    dfs(grid, visited, nr, nc, r, c);
            }
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