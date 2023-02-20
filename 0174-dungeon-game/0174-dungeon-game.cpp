class Solution {
private:
    static const int MAX = 200 + 1;
    int memory[MAX][MAX];
    vector<vector<int>> dungeon;
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
    int calculateMinimumHP(vector<vector<int>>& _dungeon) 
    {
        int result = 1;
        dungeon = _dungeon;
        memset(memory, -1, sizeof(memory));
        
        int minHealth = minHP(0, 0);
        
        if(minHealth < 0)
            result += abs(minHealth);
        
        return result;
    }
    
    int minHP(int r, int c)
    {
        // reached the end
        if(r == (int)dungeon.size()-1 && c == (int)dungeon[0].size()-1)
            return dungeon[r][c];
        
        int &ret = memory[r][c];
        if(ret != -1)
            return ret;
        
        int rightward{INT_MIN};
        if(c < (int)dungeon[0].size()-1)
            rightward = minHP(r, c+1);
        
        int downward{INT_MIN};
        if(r < (int)dungeon.size()-1)
            downward = minHP(r+1, c);
        
        return ret = dungeon[r][c] + min(0, max(rightward, downward));
    }
};