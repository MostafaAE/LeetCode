const int MAX = 100 + 1;
int memory[MAX][MAX];
vector<vector<int>> grid;
class Solution {
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
        grid = obstacleGrid;
        memset(memory, -1, sizeof(memory));
        return cntPaths(0, 0);
    }
    
    int cntPaths(int r, int c)
    {
        // invalid path
        if(r >= (int)grid.size() || c >= (int)grid[0].size() || grid[r][c])
            return 0;
        
        // reached the end (bottom-right corner)
        if(r == (int)grid.size() - 1 && c == (int)grid[0].size() - 1)
            return 1;
        
        int &ret = memory[r][c];
        if(ret != -1)
            return ret;
        
        int moveRight = cntPaths(r, c + 1);
        int moveDown = cntPaths(r + 1, c);
        
        return ret = moveRight + moveDown;
    }
};