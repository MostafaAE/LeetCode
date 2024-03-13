class Solution {
private:
    static const int MAX = 100 + 1;
    int memory[MAX][MAX], n;
    vector<vector<int>> mat;
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
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        mat = matrix;
        n = (int)mat.size();
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                memory[i][j] = INT_MAX;
        
        int result{INT_MAX};
        // In the first row: try all possible starts
        for(int c = 0 ; c < n ; c++)
            result = min(result, minFallingPath(0, c));
        
        return result;
    }
    
    int minFallingPath(int r, int c)
    {
        // out of boundaries
        if(c >= n || c < 0)
            return INT_MAX;
        
        int &ret = memory[r][c];
        if(ret != INT_MAX)
            return ret;
        
        // reached the last row
        if(r == n - 1)
            return ret = mat[r][c];
        
        int down = minFallingPath(r + 1, c);
        int leftDiagonal = minFallingPath(r + 1, c - 1);
        int rightDiagonal = minFallingPath(r + 1, c + 1);
        
        return ret = mat[r][c] + min(down, min(leftDiagonal, rightDiagonal));
    }
};