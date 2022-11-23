class Solution {
public:
    /* 
    * Approach:
    * Simulation using Depth First Search
    * 
    * Complexity:
    * Time Complexity : O(n*m)
    * Space Complexity : O(m) => auxiliary space for stack
    */
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int m{(int)grid.size()}, n{(int)grid[0].size()};
        vector<int> result;
        
        for(int i = 0 ; i < n ; i++)
            result.push_back(dfs(grid, 0, i));
        
        return result; 
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if(r == (int)grid.size())
            return c;
        
        int adjCol = c + grid[r][c];
        if(0 > adjCol || adjCol >= (int)grid[0].size() || grid[r][adjCol] != grid[r][c])
            return -1;
        
        return dfs(grid, r+1, adjCol);
    }
};