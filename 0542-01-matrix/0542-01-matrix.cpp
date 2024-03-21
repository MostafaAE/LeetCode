class Solution {
private:
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1, 1};
public:
    /* 
    * Approach:
    * Breadth-First search
    * 
    * Complexity:
    * Time Complexity : O(MN)
    * Space Complexity : O(MN)
    */
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m{(int)mat.size()}, n{(int)mat[0].size()};
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        
        for(int r = 0 ; r < m ; r++)
            for(int c = 0 ; c < n ; c++)
                if(!mat[r][c])
                    q.push({r,c}), visited[r][c] = true;
        
        int level{};
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [r, c] = q.front();
                q.pop();
                for(int d = 0 ; d < 4 ; d++)
                {
                    int nr = r + dr[d], nc = c + dc[d];
                    if(isValid(mat, nr, nc) && !visited[nr][nc])
                    {
                        visited[nr][nc] = true;
                        mat[nr][nc] = level + 1;
                        q.push({nr, nc});
                    }
                }
            }
            level++;
        }
        
        return mat;
    }
    
    bool isValid(vector<vector<int>>& mat, int nr, int nc)
    {
        if(nr < 0 || nr >= mat.size() || nc < 0 || nc >= mat[0].size())
            return false;
        return true;
    }
};