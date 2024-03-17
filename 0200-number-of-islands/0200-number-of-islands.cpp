class Solution {
private:
    // direction arrays
    // delta for: up, down, left, right
    int dr[4]{-1, 1, 0 , 0};
    int dc[4]{0, 0, -1 , 1};
public:
    /* 
    * Approach:
    * Depth first search (number of connected components).
    * 
    * Complexity:
    * Time Complexity : O(N) => O(N + E) , N = rows x cols, E = 4N => O(5N)
    * Space Complexity : O(N)
    */
    int numIslands(vector<vector<char>>& grid) 
    {
        int m{(int)grid.size()}, n{(int)grid[0].size()}, count{};
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        
        for(int r = 0 ; r < m ; r++)
            for(int c = 0 ; c < n ; c++)
                if(!visited[r][c] && grid[r][c] == '1')
                    dfs(grid, r, c, visited), count++;
            

        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited)
    {
        visited[r][c] = true;
        
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            if(isValid(grid, nr, nc) && !visited[nr][nc] && grid[nr][nc] == '1')
                dfs(grid, nr, nc, visited);
        }
    }
    
    // return true if this position INSIDE the 2D matrix
    bool isValid(vector<vector<char>>& grid, int r, int c)
    {
        if(r < 0 || r >= (int)grid.size() || c < 0 || c >= (int)grid[0].size())
            return false;
        
        return true;
    }
};