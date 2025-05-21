class Solution {
private:
    static const int MAX = 100 + 1;
    int memory[MAX][MAX];
public:
    /*
     * Approach:
     * Dynamic Programming with Memoization (Top-down)
     * 
     * The goal is to find the minimum falling path sum from top to bottom in the matrix.
     * A falling path starts at any element in the first row and chooses one element from the next row
     * that is either directly below or diagonally left/right.
     * 
     * We recursively calculate the minimum path sum starting from each element in the first row,
     * and use memoization to cache already computed results to avoid recomputation.
     *
     * Time Complexity : O(N^2) — each cell is visited once and results cached.
     * Space Complexity : O(N^2) — for the memoization table.
     */
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = (int)matrix.size();
        // Initialize memo table with INT_MAX (uncomputed)
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
                memory[i][j] = INT_MAX;
        }

        int result = INT_MAX;

        // Try all columns in the first row as possible starting points
        for(int c = 0 ; c < n ; c++)
            result = min(result, minFallingPath(0, c, matrix));
        
        return result;
    }
    
    // Recursive function to find the min falling path from (r, c) to the bottom
    int minFallingPath(int r, int c, vector<vector<int>>& matrix)
    {
        int &ret = memory[r][c];
        if(ret != INT_MAX)
            return ret; // Return cached result

        // Base case: last row, just return the value at (r, c)
        if(r == (int)matrix.size() - 1)
            return ret = matrix[r][c];
        
        // Recursive calls to the next row (down, down-left, down-right)
        int leftDiagonal = INT_MAX, rightDiagonal = INT_MAX;
        if(c > 0)
            leftDiagonal = minFallingPath(r + 1, c - 1, matrix);
        if(c < (int)matrix.size() - 1)
            rightDiagonal = minFallingPath(r + 1, c + 1, matrix);
        int down = minFallingPath(r + 1, c, matrix);
        
        // Store and return the minimum path sum from this cell
        return ret = matrix[r][c] + min(down, min(leftDiagonal, rightDiagonal));
    }
};
