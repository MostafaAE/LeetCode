class Solution {
private:
    static const int MAX = 200 + 1;
    int memory[MAX][MAX];
    vector<vector<int>> grid;
    int m, n;
    
public:
    /* 
    * Approach:
    * Dynamic Programming Memoization (DP on Grid)
    * 
    * Complexity:
    * Time Complexity : O(m*n)
    * Space Complexity : O(m*n)
    */
    int minPathSum(vector<vector<int>>& _grid) 
    {
        grid = _grid;
        m = (int)grid.size(), n = (int)grid[0].size();
        
        memset(memory, -1, sizeof(memory));
        
        return pathSum(0, 0);
        
    }
    
    int pathSum(int r, int c)
    {
        if(r >= m || c >= n)
            return INT_MAX;
        
        if(r == m - 1 && c == n - 1)
            return grid[r][c];
        
        int &ret = memory [r][c];
        if(ret != -1)
            return ret;
        
        int right = pathSum(r, c + 1);
        int down = pathSum(r + 1, c);
        
        return ret = grid[r][c] + min(right, down);
    }
};