class Solution {
public:
    /**
     * Approach:
     * - Initialize a result matrix of size rows x cols filled with 0s.
     * - Set the first column of the result matrix with the values from the rowSum vector.
     * - Iterate through each column and each row, adjusting the values based on the remaining column sum.
     * - For each cell, if the remaining column sum is greater than or equal to the cell value, subtract the cell value from the column sum.
     * - If the remaining column sum is less than the cell value, update the next cell in the same row with the difference, set the current cell value to the remaining column sum, and set the column sum to 0.
     *
     * Complexity:
     * - Time Complexity: O(m * n)
     * - Space Complexity: O(1)
     */
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) 
    {
        int rows = rowSum.size();
        int cols = colSum.size();
        
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        
        for(int r = 0 ; r < rows ; ++r)
        {
            result[r][0] = rowSum[r];
        }
        
        for(int c = 0 ; c < cols ; ++c)
        {
            for(int r = 0 ; r < rows ; ++r)
            {
                if(colSum[c] >= result[r][c])
                    colSum[c] -= result[r][c];
                else
                {
                    result[r][c+1] += result[r][c] - colSum[c];
                    result[r][c] = colSum[c];
                    colSum[c] = 0;
                }
            }
        }
        
        return result;
    }
};