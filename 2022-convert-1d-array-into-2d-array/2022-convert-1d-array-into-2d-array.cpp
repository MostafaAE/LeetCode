class Solution {
public:
    /**
     * Approach:
     * - Check if the size of the original array matches the desired dimensions `m * n`.
     * - If not, return an empty 2D array.
     * - Create a 2D vector `result` with dimensions `m x n`.
     * - Use a single loop to fill the 2D vector by mapping the 1D index to 2D coordinates.
     * 
     * Complexity:
     * - Time Complexity: O(m * n), where `m` is the number of rows and `n` is the number of columns.
     * - Space Complexity: O(1)
     */
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        int orgSize = original.size();
         
        if(orgSize != m*n)
            return {};
        
       vector<vector<int>> result(m, vector<int>(n));
        for(int i = 0 ; i < orgSize ; ++i)
            result[i/n][i%n] = original[i];
        
        return result;
    }
};