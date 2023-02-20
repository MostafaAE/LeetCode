class Solution {
private:
    static const int MAX = 300 + 1;
    int memory[MAX][MAX];
    vector<vector<char>> mat;
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
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        mat = matrix;
        memset(memory, -1, sizeof(memory));
        
        int maxSqSide{INT_MIN};
        for(int r = 0 ; r < (int)mat.size() ; r++)
            for(int c = 0 ; c < (int)mat[0].size() ; c++)
                maxSqSide = max(maxSqSide, maxSquareSide(r, c));
        
        return maxSqSide * maxSqSide;
    }
    
    int maxSquareSide(int r, int c)
    {
        if(r < 0 || c < 0 || mat[r][c] == '0')
            return 0;
        
        int &ret = memory[r][c];
        if(ret != -1)
            return ret;

        int up = maxSquareSide(r-1, c);
        int left = maxSquareSide(r, c-1);
        int diagonal = maxSquareSide(r-1, c-1);
    
        return ret = 1 + min(up, min(left, diagonal));
    }
};