class Solution {
private:
    static const int MAX = 100 + 1;
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
     * Time Complexity : O(MN) 
     * Space Complexity : O(MN) where M is the max row, and N is the max col
     */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        memset(memory, -1, sizeof(memory));
        grid = obstacleGrid;
        
        return countUniquePaths(0, 0);
    }
    
    
    int countUniquePaths(int row, int col)
    {
        // out of boundaries or an obstacle
        if(row >= (int)grid.size() || col >= (int)grid[0].size()  || grid[row][col])
            return 0;
        
        // valid path
        if(row == (int)grid.size()-1 && col == (int)grid[0].size()-1)
            return 1;
        
        int &ret = memory[row][col];
        if(ret != -1)
            return ret;
        
        int goRight = countUniquePaths(row, col + 1);
        int goDown = countUniquePaths(row + 1, col);
        
        return ret = goRight + goDown;
    }
};