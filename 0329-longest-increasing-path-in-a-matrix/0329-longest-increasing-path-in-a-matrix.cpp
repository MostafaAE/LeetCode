class Solution {
private:
    int dr[4]{-1, 1, 0 , 0};
    int dc[4]{0, 0, -1, 1};
public:
    /* 
    * Approach:
    * Topological Sort
    * 
    * Complexity:
    * Time Complexity : O(n*m)
    * Space Complexity : O(n*m)
    */
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int m{(int)matrix.size()}, n{(int)matrix[0].size()};
        
        vector<vector<int>> indegree(m, vector<int>(n));
        
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                for(int d = 0 ; d < 4 ; d++)
                {
                    int nr = i + dr[d], nc = j + dc[d];
                    if(isValid(nr, nc, matrix) && matrix[nr][nc] < matrix[i][j])
                        indegree[i][j]++;
                }
        
        queue<pair<int, int>> ready;
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                if(!indegree[i][j])
                    ready.push({i, j});
        
        int level{};
        while(!ready.empty())
        {
            int sz = ready.size();
            while(sz--)
            {
                auto [r, c] = ready.front();
                ready.pop();
                
                for(int d = 0 ; d < 4 ; d++)
                {
                    int nr = r + dr[d], nc = c + dc[d];
                    if(isValid(nr, nc, matrix) && matrix[nr][nc] > matrix[r][c]&& --indegree[nr][nc] == 0)
                        ready.push({nr, nc});
                }
            }
            level++;
        }
        
        return level;
        
    }
    
    bool isValid(int nr, int nc, vector<vector<int>>& matrix)
    {
        if(0 > nr || nr >= (int)matrix.size() || 0 > nc || nc >= (int)matrix[0].size())
            return false;
        return true;
    }
};