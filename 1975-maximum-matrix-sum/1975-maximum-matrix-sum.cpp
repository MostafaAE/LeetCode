class Solution {
public:
    /**
     * Approach:
     * 1. Traverse the entire matrix to calculate:
     *    - The total sum of the absolute values of all elements (`result`).
     *    - The count of negative numbers (`negCount`).
     *    - The smallest absolute value (`absMin`).
     * 2. If the count of negative numbers (`negCount`) is odd, adjust the result by subtracting twice the smallest absolute value.
     *    - This comes from the observation that we can have only 1 negative number in the matrix after doing the operation "any" number of times.
     * 
     * Complexity:
     * Time Complexity: O(n^2)
     * - Traverse all elements in an `n x n` matrix once.
     * Space Complexity: O(1)
     */
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        long long result{};
        int n = matrix.size(), absMin{INT_MAX}, negCount{};
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(matrix[i][j] < 0)
                    ++negCount;
                
                result += abs(matrix[i][j]);
                absMin = min(absMin, abs(matrix[i][j]));
            }
        }
        
        if(negCount&1)
            result -= 2 * absMin;
        
        return result;
    }
};