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
    * Time Complexity : O(N) => O(N + E) , N = mxn, E = 4N => O(5N)
    * Space Complexity : O(N)
    */
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int m {(int)grid2.size()}, n {(int)grid2[0].size()}, count{};
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        for(int r = 0 ; r < m ; r++)
        {
            for(int c = 0 ; c < n ; c++)
            {
                bool isSubIsland = true;
                if(!visited[r][c] && grid2[r][c])
                {
                    dfs(grid1, grid2, r, c ,visited, isSubIsland);
                    count += isSubIsland;
                }    
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, vector<vector<bool>>& visited, bool& isSubIsland)
    {
        if(!grid1[r][c])
            isSubIsland = false; 
        
        visited[r][c] = true;
        
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            if(isValid(nr, nc, grid2) && !visited[nr][nc] && grid2[nr][nc])
                dfs(grid1, grid2, nr, nc, visited, isSubIsland);
        }
    }
    
    // return true if this position INSIDE the 2D matrix
    bool isValid(int nr, int nc, vector<vector<int>>& grid)
    {
        if(nr < 0 || nr >= (int)grid.size() || nc < 0 || nc >= (int)grid[0].size())
            return false;
        return true;
    }
};