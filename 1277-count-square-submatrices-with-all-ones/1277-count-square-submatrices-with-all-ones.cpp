class Solution 
{
private:
    static const int MAX = 300 + 1;
    int memory[MAX][MAX];
    vector<vector<int>> matrix;
    
public:
    /**
     * Approach:
     * 1. Use dynamic programming with memoization to calculate the number of square submatrices with all 1s.
     * 2. For each cell (i, j), calculate the largest square submatrix ending at that cell using a helper function `countSq`.
     *    - If matrix[i][j] == 0, return 0 (no square can end at this cell).
     *    - Otherwise, the size of the largest square is determined by the minimum square size possible among the cell above, 
     *      to the left, and the top-left diagonal cell.
     *    - Store and reuse results in `memory` array to avoid redundant calculations.
     * 3. Accumulate results from each cell to get the total number of squares.
     * 
     * Time Complexity: O(n * m), where n and m are the dimensions of the matrix, as each cell is computed once.
     * Space Complexity: O(n * m), for the memoization array `memory` and the matrix copy.
     */
    int countSquares(vector<vector<int>>& _matrix) 
    {
        memset(memory, -1, sizeof(memory));
        matrix = _matrix;
        
        int result{};
        for(int i = 0 ; i < matrix.size() ; ++i)
            for(int j = 0 ; j < matrix[0].size() ; ++j)
                result += countSq(i, j);
        
        return result;
    }
    
    int countSq(int i, int j)
    {
        if(i < 0 || j < 0 || matrix[i][j] == 0)
            return 0;
        
        int& ret = memory[i][j];
        if(ret != -1)
            return ret;
        
        int up = countSq(i-1, j);
        int left = countSq(i, j-1);
        int leftDiag = countSq(i-1, j-1);
        
        return ret = 1 + min(up, min(left, leftDiag));
    }
};
