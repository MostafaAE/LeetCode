class Solution {
private:
int dr[4]{1, -1, 0, 0};
int dc[4]{0, 0, 1, -1};
    
public:
    /* 
    * Approach:
    * Breadth first search
    * 
    * Complexity:
    * Time Complexity : O(m*n)
    * Space Complexity : O(m*n)
    */
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int m{(int)heights.size()}, n{(int)heights[0].size()};
        
        vector<vector<bool>> atlanticReachable(m, vector<bool>(n));
        vector<vector<bool>> pacificReachable(m, vector<bool>(n));
        
        vector<pair<int,int>> pacificStartings, atlanticStartings;
        // get 1st/last row/col as starting points
        for (int r = 0; r < m ; r++)
        {
            pacificStartings.push_back({r, 0});
            atlanticStartings.push_back({r, n-1});
        }
        for (int c = 0; c < n ; c++)
        {
            pacificStartings.push_back({0, c});
            atlanticStartings.push_back({m-1, c});
        }
        
        bfs(heights, pacificReachable, pacificStartings);
        bfs(heights, atlanticReachable, atlanticStartings);
        
        // building the result
        vector<vector<int>> result;
        for(int r = 0 ; r < m ; r++)
            for(int c = 0 ; c < n ; c++)
                if(atlanticReachable[r][c] && pacificReachable[r][c])
                    result.push_back({r,c});
    
        return result;
    }
    
    void bfs(vector<vector<int>>& heights, vector<vector<bool>> &visited, vector<pair<int,int>> &startings)
    {
        queue<pair<int, int>> q;
        for(auto &p : startings)
            q.push(p), visited[p.first][p.second] = 1;
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto &p = q.front();
                int r = p.first, c = p.second;
                q.pop();
                
                for (int d = 0; d < 4; ++d) 
                {
				    int nr = r + dr[d], nc = c + dc[d];
                    if(isValid(nr, nc, heights) && !visited[nr][nc] && heights[nr][nc] >= heights[r][c])
                        q.push({nr, nc}), visited[nr][nc] = 1;
                }
            }
        }
    }
    
    bool isValid(int nr, int nc, vector<vector<int>> &grid)
    {
        if (nr < 0 || nr >= (int)grid.size() || nc < 0 || nc >= (int)grid[0].size())
            return false;
        return true;
    }
};