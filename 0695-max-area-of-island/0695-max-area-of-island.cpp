class Solution {
private:
    int dr[4]{0, 0, -1, 1};
    int dc[4]{-1, 1, 0, 0};
public:
    /* 
    * Approach:
    * Perform DFS on the grid to find the size of each connected component (island), updating the maximum area accordingly.
    * 
    * Complexity:
    * Time Complexity : O(MN)
    * Space Complexity : O(MN)
    */
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int maxArea{}, m{(int)grid.size()}, n{(int)grid[0].size()};
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        
        for(int r = 0 ; r < m ; ++r)
            for(int c = 0 ; c < n ; ++c)
                if(grid[r][c] && !visited[r][c])
                    maxArea = max(maxArea, dfs(grid, r, c, visited));
    
        return maxArea;
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited)
    {
        visited[r][c] = true;
        int count{1};
        for(int d = 0 ; d < 4 ; ++d)
        {
            int nr = r + dr[d], nc = c + dc[d];
            if(isValid(grid, nr, nc) && grid[nr][nc] && !visited[nr][nc])
                count += dfs(grid, nr, nc, visited);
        }
        
        return count;
    }
    
    bool isValid(vector<vector<int>>& grid, int r, int c)
    {
        if(r < 0 || r >= (int)grid.size() || c < 0 || c >= (int)grid[0].size())
            return false;
        return true;
    }
};