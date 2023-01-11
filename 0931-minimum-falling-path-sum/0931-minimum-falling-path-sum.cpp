class Solution {
private:
    static const int MAX = 100 + 1;
    int memory[MAX][MAX];
    vector<vector<int>> matrix;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * DP on Grid
     *
     * Complexity:
     * Time Complexity : O(N^2) 
     * Space Complexity : O(N^2)
     */
    int minFallingPathSum(vector<vector<int>>& mat) 
    {
        int n{(int)mat.size()}, result{INT_MAX};
        matrix = mat;
        memset(memory, -1, sizeof(memory));
        
        // In the first row: try all possible starts
        for(int c = 0 ; c < n ; c++)
            result = min(result, minPath(0, c));
        
        return result;
    }
    
    int minPath(int r, int c)
    {
        // reached last row
        if(r == (int)matrix.size()-1)
            return matrix[r][c];
        
        int &ret = memory[r][c];
        if(ret != -1)
            return ret;
        
        int diagLeft{INT_MAX}, diagRight{INT_MAX};
        
        if(c - 1 >= 0)
            diagLeft = minPath(r+1, c-1);
        
        if(c + 1 < (int)matrix.size())
            diagRight = minPath(r+1, c+1);
        
        int down = minPath(r+1, c);
        
        return ret = matrix[r][c] + min(down, min(diagLeft, diagRight));
    }
};