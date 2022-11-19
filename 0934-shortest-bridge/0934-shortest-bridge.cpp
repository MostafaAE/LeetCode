class Solution {
private:
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1 , 1};
public:
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int n = (int)grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n));
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j])
                {
                    getConnectedIsland(grid, i, j, q, visited);
                    break;
                }
            }
            if(!q.empty())
                break;
        }
        
        
        int level{};
        while(!q.empty())
        {
            int sz = q.size();

            while(sz--)
            {
                auto [row, col] = q.front();
                q.pop();
                
                for(int d = 0 ; d < 4 ; d++)
                {
                    int nr = row + dr[d], nc = col + dc[d];
                    if(isValid(nr, nc, grid) && !visited[nr][nc])
                    {
                        // reached the other island
                        if(grid[nr][nc])
                            return level;
                        else
                        {
                            q.push({nr, nc});
                            visited[nr][nc] = 1;
                        }
                    }
                }
            }
            level++;
        }
                    
        return 0;
        
    }
    
    void getConnectedIsland(vector<vector<int>>& grid, int r, int c, queue<pair<int, int>>& island, vector<vector<bool>>& visited)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        island.push({r, c});
        visited[r][c] = 1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [row, col] = q.front();
                q.pop();
                
                for(int d = 0 ; d < 4 ; d++)
                {
                    int nr = row + dr[d], nc = col + dc[d];
                    if(isValid(nr, nc, grid) && !visited[nr][nc] && grid[nr][nc])
                    {
                        q.push({nr, nc});
                        island.push({nr, nc});
                        visited[nr][nc] = 1;
                    }
                }
            }
        }
    }
    
    bool isValid(int nr, int nc, vector<vector<int>>& grid)
    {
        if(0 > nr || nr >= (int)grid.size() || 0 > nc || nc >= (int)grid.size())
            return false;
        return true;
    }
        
};