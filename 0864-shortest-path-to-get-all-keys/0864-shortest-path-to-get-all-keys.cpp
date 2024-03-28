class Solution {
private:
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1, 1};
public:
    /* 
    * Approach:
    * Breadth-First search with states.
    * 
    * Complexity:
    * Time Complexity : O(M.N.2^k) 
    * Space Complexity : O(M.N.2^k)
    */
    int shortestPathAllKeys(vector<string>& grid) 
    {
        int m{(int)grid.size()}, n{(int)grid[0].size()}, keysCount{};
        
        auto visited = vector<vector<unordered_set<int>>>(m,vector<unordered_set<int>>(n));
        queue<vector<int>> q; // {x,y,state}
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == '@')
                {
                    q.push({i, j, 0});
                    visited[i][j].insert(0);
                }
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    keysCount++;
            }
        }
        
        // represent each key as a bit for example if we have 3 key finalState = 111 (7)
        int finalState = 0;
        for (int i = 0; i < keysCount; i++)
            finalState |= (1<<i);
        
        int level{};
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int r = q.front()[0];
                int c = q.front()[1];
                int state = q.front()[2];
                q.pop();
                
                for(int d = 0 ; d < 4 ; d++)
                {
                    int nr = r + dr[d], nc = c + dc[d], newState = state;
                    if(isValid(grid, nr, nc) && grid[nr][nc] != '#')
                    {
                        // found a lock with no key
                        if('A' <= grid[nr][nc] && grid[nr][nc] <= 'F' && ((state>>(grid[nr][nc]-'A'))&1)==0)
                            continue;
                        
                        // found a key
                        if('a' <= grid[nr][nc] && grid[nr][nc] <= 'f')
                            // mark this key as found and start a new state
                            newState |= (1<<(grid[nr][nc] - 'a'));
                        
                        // this new state already visited
                        if(visited[nr][nc].count(newState))
                            continue;
                        
                        // found all keys
                        if(newState == finalState)
                            return level + 1;
                        
                        visited[nr][nc].insert(newState);
                        q.push({nr, nc, newState});
                    }
                }
            }
            level++;
        }
        return -1;
    }
    
    bool isValid(vector<string>& grid, int r, int c)
    {
        int m{(int)grid.size()}, n{(int)grid[0].size()};
        if(r < 0 || r >= m || c < 0 || c >= n)
            return false;
        return true;
    }
};