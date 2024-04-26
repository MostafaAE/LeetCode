class Solution {
private:
    static const int MAX = 200 + 1;
    int memory[MAX][MAX];
    vector<vector<int>> grid;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * DP on Grid
     *
     * Complexity:
     * Time Complexity : O(N^3) 
     * Space Complexity : O(N^2)
     */
    int minFallingPathSum(vector<vector<int>>& _grid) 
    {
        int minPath{INT_MAX};
        grid = _grid;
        
        for(int i = 0 ; i < MAX ; i++)
            for(int j = 0 ; j < MAX ; j++)
                memory[i][j] = INT_MAX;
        
        // In the first row: try all possible starts
        for(int c = 0 ; c < (int)grid.size() ; c++)
            minPath = min(minPath, minFallingPath(0, c));
        
        return minPath;
    }
    
    int minFallingPath(int r, int c)
    {
        // out of boundaries
        if(r >= grid.size())
            return 0;
        
        int &ret = memory[r][c];
        if(ret != INT_MAX)
            return ret;
        
        
        for(int i = 0 ; i < grid.size() ; i++)
            if(i != c)
                ret = min(ret, minFallingPath(r + 1, i));
        
        if(ret == INT_MAX)
            ret = 0;
        
        ret += grid[r][c];
        return ret;
    }
};