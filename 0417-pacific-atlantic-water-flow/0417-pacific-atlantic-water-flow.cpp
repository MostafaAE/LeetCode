class Solution {
private:
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
public:
    /* 
    * Approach:
    * Breadth first search
    * 
    * Complexity:
    * Time Complexity : O(MN)
    * Space Complexity : O(MN)
    */
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int n{(int)heights.size()}, m{(int)heights[0].size()};
        vector<vector<bool>> touchesPacific(n, vector<bool>(m));
        vector<vector<bool>> touchesAtlantic(n, vector<bool>(m));
        
        vector<vector<int>> result;
        
        // Prepare pacific and atlantic queue
        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;
        
        for(int col = 0 ; col < m ; col++)
        {
            pacificQueue.push({0, col});
            atlanticQueue.push({n-1, col});
            touchesPacific[0][col] = true;
            touchesAtlantic[n-1][col] = true;
        }
        for(int row = 0 ; row < n ; row++)
        {
            pacificQueue.push({row, 0});
            atlanticQueue.push({row, m-1});
            touchesPacific[row][0] = true;
            touchesAtlantic[row][m-1] = true;
        }
        
        bfs(pacificQueue, heights, touchesPacific);
        bfs(atlanticQueue, heights, touchesAtlantic);
            
        for(int row = 0 ; row < n ; row++)
        {
            for(int col = 0 ; col < m ; col++)
                if(touchesPacific[row][col] && touchesAtlantic[row][col])
                    result.push_back({row, col});
        }
        
        return result;
    }
            
    void bfs(queue<pair<int, int>>& queue, vector<vector<int>>& heights, vector<vector<bool>>& visited)
    {
        while(!queue.empty())
        {
            int sz{(int)queue.size()};
            while(sz--)
            {
                auto [r, c] = queue.front();
                queue.pop();
                
                for(int d = 0; d < 4 ; d++)
                {
                    int nr = r + dx[d];
                    int nc = c + dy[d];
                    if(isValid(nr, nc, heights) && heights[nr][nc] >= heights[r][c] && !visited[nr][nc])
                    {
                        visited[nr][nc] = true;
                        queue.push({nr, nc});
                    }
                }
            }
        }
        
    }
            
    bool isValid(int r, int c, vector<vector<int>>& heights)
    {
        if(r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size())
            return false;
        return true;
    }
};