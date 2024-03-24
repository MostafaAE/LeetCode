class Solution {
private:
    int dr[8]{-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[8]{-1, 0, 1, -1, 1, -1, 0 ,1};
public:
    /* 
    * Approach:
    * Breadth-First search
    * 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(n^2)
    */
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n{(int)grid.size()};
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
        
        q.push({0,0});
        visited[0][0] = true;
        int level{1};
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [r, c] = q.front();
                q.pop();
                if(r == n-1 && c == n-1)
                    return level;
                
                for(int d = 0 ; d < 8 ; d++)
                {
                    int nr = r + dr[d], nc = c + dc[d];
                    if(isValid(n, nr, nc) && !visited[nr][nc] && !grid[nr][nc])
                        q.push({nr, nc}), visited[nr][nc] = true;;
                }
            }
            level++;
        }
        
        return -1;
    }
    
    bool isValid(int n, int nr, int nc)
    {
        if(nr < 0 || nr >= n || nc < 0 || nc >= n)
            return false;
        return true;
    }
};