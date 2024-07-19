class Solution {
public:
    /**
     * Approach:
     * - Find the minimum value in each row and store it in a vector `minInRow`.
     * - Find the maximum value in each column and store it in a vector `maxInCol`.
     * - Iterate through the matrix and check for values that are both the minimum in their row
     *   and the maximum in their column. Add such values to the result vector.
     *
     * Complexity:
     * - Time Complexity: O(m * n)
     * - Space Complexity: O(m + n)
     */
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> minInRow(rows, INT_MAX), maxInCol(cols, INT_MIN);
        vector<int> result;
        
        for(int i = 0 ; i < rows ; ++i)
        {
            for(int j = 0 ; j < cols ; ++j)
            {
                minInRow[i] = min(minInRow[i], matrix[i][j]);
                maxInCol[j] = max(maxInCol[j], matrix[i][j]);
            }
        }
        
        for(int i = 0 ; i < rows ; ++i)
            for(int j = 0 ; j < cols ; ++j)
                if(matrix[i][j] == minInRow[i] && matrix[i][j] == maxInCol[j])
                    result.push_back(matrix[i][j]);
        
        return result;
    }
};