const int MAX = 300 + 1;
int memory[MAX][MAX];
vector<vector<char>> mat;
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
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m{(int)matrix.size()}, n{(int)matrix[0].size()};
        
        mat = matrix;
        memset(memory, -1, sizeof(memory));
        
        maxSqSide(m-1, n-1);
        
        int maxSide{INT_MIN};
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                maxSide = max(maxSide, maxSqSide(i, j));
        
        return maxSide*maxSide;
    }
    
    int maxSqSide(int r, int c)
    {
        if(r < 0 || c < 0 || mat[r][c] == '0')
            return 0;
        
        int &ret = memory[r][c];
        if(ret != -1)
            return ret;
        
        int up = maxSqSide(r-1, c);
        int left = maxSqSide(r, c-1);
        int diagonal = maxSqSide(r-1, c-1);
        
        return ret = 1 + min(up, min(left, diagonal));
        
    }
};