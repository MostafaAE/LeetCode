/*
 * Approach:
 * To rotate an `n x n` matrix 90 degrees clockwise in-place:
 * 
 * 1. **Transpose** the matrix:
 *    - Swap matrix[i][j] with matrix[j][i] for all i < j.
 *    - This flips the matrix over its main diagonal.
 *
 * 2. **Reflect** the matrix horizontally:
 *    - For each row, swap the elements symmetrically with respect to the vertical center.
 *    - This produces the final rotated matrix.
 *
 * These two steps combined achieve a 90-degree clockwise rotation.

 * Time Complexity  : O(n^2), we visit each cell once in transpose and once in reflect.
 * Space Complexity : O(1), all operations are done in-place without extra memory.
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        // Step 1: Transpose the matrix over the main diagonal
        transpose(matrix);
        
        // Step 2: Reflect the matrix over the vertical middle axis
        reflect(matrix);     
    }
    
    void transpose(vector<vector<int>>& matrix)
    {
        int n = (int)matrix.size();
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void reflect(vector<vector<int>>& matrix)
    {
        int n = (int)matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n / 2; ++j)
            {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};