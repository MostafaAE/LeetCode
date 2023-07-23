const int MAX = 50 + 1, MOD = 1e9 + 7;
int memory[MAX][MAX][MAX];
int m, n;
int dr[4]{-1, 1, 0, 0};
int dc[4]{0, 0, -1, 1};
class Solution {
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
    int findPaths(int m_, int n_, int maxMove, int startRow, int startColumn) 
    {
        m = m_;
        n = n_;
        memset(memory, -1, sizeof(memory));
        
        return numPaths(startRow, startColumn, maxMove);
    }
    
    int numPaths(int row, int col, int remainingMoves)
    {
        // out of boundary
        if(row >= m || row < 0 || col >=n || col < 0)
            return 1;
        
        if(remainingMoves == 0)
            return 0;

        int &ret = memory[row][col][remainingMoves];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = row + dr[d], nc = col + dc[d];
            ret = (ret + numPaths(nr, nc, remainingMoves - 1)) % MOD;
        }
        
        return ret;
    }
};