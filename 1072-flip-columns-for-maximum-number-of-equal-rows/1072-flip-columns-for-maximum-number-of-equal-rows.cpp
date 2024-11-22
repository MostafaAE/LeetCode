class Solution {
public:
    /**
     * Approach:
     *  1. Iterate through each row in the `matrix`.
     *  2. For each row, build two strings (`positions[0]` and `positions[1]`):
     *    - `positions[0]`: Represents the column indices for which the value is 0.
     *    - `positions[1]`: Represents the column indices for which the value is 1.
     *  3. Use an unordered map (`colPositionsToCount`) to count the occurrences of each pattern of column indices.
     *    - Increment the count for both `positions[0]` and `positions[1]` in the map.
     *  4. Keep track of the maximum count (`result`) found across all rows.
     *  5. The result is the maximum number of rows that can be made identical by flipping columns.
     * 
     * Complexity:
     * - Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
     * - Space Complexity: O(m * n), for storing the column positions in the map.
     */
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size(), result{};
        unordered_map<string, int> colPositionsToCount;
        
        for(int i = 0 ; i < m ; ++i)
        {
            vector<string> positions(2, "");
            for(int j = 0 ; j < n ; ++j)
                positions[matrix[i][j]] += to_string(j) + ",";
            
            result = max(result, 
                         max(++colPositionsToCount[positions[0]], 
                             ++colPositionsToCount[positions[1]]));
        }
        
        return result;
    }
};