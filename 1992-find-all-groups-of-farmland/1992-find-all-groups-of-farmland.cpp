class Solution {
private:
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1, 1};
    
public:
    /* 
    * Approach:
    * Depth first search (smallest and largest x-coordinate and y-coordinate for each connected component).
    * 
    * Complexity:
    * Time Complexity : O(MN) => O(MN + E) , E = 4MN => O(5MN)
    * Space Complexity : O(MN)
    */
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
        int m{(int)land.size()}, n{(int)land[0].size()};
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        vector<vector<int>> result;
        
        for(int r = 0 ; r < m ; ++r)
        {
            for(int c = 0 ; c < n ; ++c)
            {
                if(!visited[r][c] && land[r][c])
                {
                    auto [endRow, endCol] = dfs(land, r, c, visited);
                    result.push_back({r, c, endRow, endCol});
                }
            }
        }
        
        return result;
    }
    
    pair<int, int> dfs(vector<vector<int>>& land, int r, int c, vector<vector<bool>>& visited)
    {
        visited[r][c] = true;
        pair<int, int> result = make_pair(r, c);
        
        for(int d = 0 ; d < 4 ; ++d)
        {
            int nr = r + dr[d], nc = c + dc[d];
            if(isValid(nr, nc, land) && !visited[nr][nc] && land[nr][nc])
                result = max(result, dfs(land, nr, nc, visited));
        }
        return result;
    }
    
    bool isValid(int nr, int nc, vector<vector<int>>& land)
    {
        if(nr < 0 || nr >= land.size() || nc < 0 || nc >= land[0].size())
            return false;
        return true;
    }
};