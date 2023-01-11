class Solution {
private:
    static const int MAX = 50 + 1;
    int memory[MAX][MAX][MAX];
    int m, n;
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1, 1};
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * DP on Grid (Counting)
     *
     * Complexity:
     * Time Complexity : O(MNK) 
     * Space Complexity : O(MNK) where M is the rows, N is the cols, and K is the max moves
     */
    int findPaths(int _m, int _n, int maxMove, int startRow, int startColumn) 
    {
        m = _m;
        n = _n;
        memset(memory, -1, sizeof(memory));
        return pathsCount(startRow, startColumn, maxMove);
    }
    
    int pathsCount(int r, int c, int moves)
    {
        if(outOfBound(r, c))
            return 1;
        
        if(!moves)
            return 0;
        
        int &ret = memory[r][c][moves];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            ret = (ret + pathsCount(nr, nc, moves - 1)) % int(1e9+7);
        }
        
        return ret;
    }
    
    bool outOfBound(int r, int c)
    {
        if(0 > r || r >= m || 0 > c || c >= n)
            return true;
        
        return false;
    }
};