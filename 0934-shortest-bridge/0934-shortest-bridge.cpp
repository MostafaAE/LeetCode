class Solution {
private:
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1 , 1};
public:
    /* 
    * Approach:
    * Breadth first search
    * 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(n^2)
    */
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int n = (int)grid.size();
        queue<pair<int, int>> q; // this queue will contain the starting points for the BFS
        vector<vector<bool>> visited(n, vector<bool>(n));
        
        // get the starting points
        for(int i = 0 ; i < n && q.empty() ; i++)
            for(int j = 0 ; j < n ; j++)
                if(grid[i][j])
                {
                    getConnectedIsland(grid, i, j, q, visited);
                    break;
                }
        
        // get the shortest bridge
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
    
    // this function takes a starting point from one island and gets all the connected cells from 
    // the same island (connected component)
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