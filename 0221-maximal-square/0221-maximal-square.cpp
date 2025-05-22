class Solution {
private:
    static const int MAX = 300 + 1;
    int memory[MAX][MAX];
    vector<vector<char>> mat;

public:
    /*
     * Approach:
     * Dynamic Programming (Memoization)
     * 
     * We define a recursive DP function `maxSqSide(r, c)` that returns the side length of the largest square
     * that ends at cell (r, c).
     * 
     * The recurrence relation is:
     * - If cell (r, c) == '0' → no square ends here → return 0
     * - Else, the square size is:
     *   1 + min of:
     *     - maxSqSide(r-1, c)      → square above
     *     - maxSqSide(r, c-1)      → square to the left
     *     - maxSqSide(r-1, c-1)    → square diagonally above-left
     * 
     * We apply memoization to avoid recomputing overlapping subproblems.
     *
     * Time Complexity: O(M * N)
     * - We visit each cell once and memoize the result.
     *
     * Space Complexity: O(M * N)
     * - For the memoization table.
     */
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        mat = matrix;

        // Initialize memory with -1 to denote uncomputed states
        memset(memory, -1, sizeof(memory));

        int maxSide = 0;

        // Try to compute the largest square ending at every cell
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                maxSide = max(maxSide, maxSqSide(i, j));
            }
        }

        return maxSide * maxSide; // area = side * side
    }

    int maxSqSide(int r, int c)
    {
        // Base case: out of bounds or cell is '0' → no square can end here
        if(r < 0 || c < 0 || mat[r][c] == '0')
            return 0;

        int &ret = memory[r][c];
        if(ret != -1)
            return ret;

        // Recurse to get min of adjacent squares and add 1
        int up = maxSqSide(r - 1, c);
        int left = maxSqSide(r, c - 1);
        int diag = maxSqSide(r - 1, c - 1);

        return ret = 1 + min(up, min(left, diag));
    }
};