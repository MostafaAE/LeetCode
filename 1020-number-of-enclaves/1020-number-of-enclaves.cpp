class Solution {
private:
    int dr[4]{-1, 1, 0, 0}, dc[4]{0, 0, -1, 1};
public:
    /* 
    * Approach:
    * Apply multi-source BFS from the boundary lands
    * 
    * Complexity:
    * Time Complexity : O(MN)
    * Space Complexity : O(MN)
    */
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m{(int)grid.size()}, n{(int)grid[0].size()}, count{};
        queue<pair<int, int>> q;
        
        // put all the boundary lands in the queue
        for(int c = 0 ; c < n ; c++)
        {
            if(grid[0][c])
                q.push({0, c}), grid[0][c] = 0;
            if(grid[m-1][c])
                q.push({m-1, c}), grid[m-1][c] = 0;
        }
        
        for(int r = 0 ; r < m ; r++)
        {
            if(grid[r][0])
                q.push({r, 0}), grid[r][0] = 0;
            if(grid[r][n-1])
                q.push({r, n-1}), grid[r][n-1] = 0;
        }
        
        // apply multi source BFS from the boundary lands
        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            
            for(int d = 0 ; d < 4 ; d++)
            {
                int nr = r + dr[d], nc = c + dc[d];
                if(isValid(grid, nr, nc) && grid[nr][nc])
                    q.push({nr, nc}), grid[nr][nc] = 0;
            }
        }
        
        // count islands
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                count += grid[i][j];
        
        return count;
    }
    
    bool isValid(vector<vector<int>>& grid, int nr, int nc)
    {
        if(nr < 0 || nr >= (int)grid.size() || nc < 0 || nc >= (int)grid[0].size())
            return false;
        return true;
    }
};