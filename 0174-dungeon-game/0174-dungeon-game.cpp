const int MAX = 200 + 1;
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
     * Space Complexity : O(MN) where M is the rows, N is the cols
     */
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        grid = dungeon;
        memset(memory, -1, sizeof(memory));
        
        return 1 + abs(minHP(0, 0));
    }
    
    int minHP(int r, int c)
    {
        if(r >= (int)grid.size() || c >= (int)grid[0].size())
            return INT_MIN;
        
        // reached the end
        if(r == (int)grid.size()-1 && c == (int)grid[0].size()-1)
            return min(grid[r][c], 0);
        
        int &ret = memory[r][c];
        if(ret != -1)
            return ret;
        
        int rightward = minHP(r, c+1);
        int downward = minHP(r+1, c);
        
        return ret = min(grid[r][c]+max(rightward, downward), 0);
    }
};