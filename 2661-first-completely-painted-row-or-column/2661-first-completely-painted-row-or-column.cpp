class Solution {
public:
    /**
     * Approach:
     * - Create a mapping from each matrix value to its position in the grid.
     * - Use two arrays, `paintedRows` and `paintedColumns`, to track how many cells have been "painted" in each row and column.
     * - Iterate through the `arr` array and update the corresponding row and column counts for each value.
     * - Return the first index where a row or column is completely painted.
     * 
     * Complexity:
     * - Time: O(m * n), where m and n are the dimensions of the matrix.
     * - Space: O(m * n)
     */
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        
        // Map matrix values to their positions (row, col)
        unordered_map<int, pair<int, int>> valToPosition;
        
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                valToPosition[mat[r][c]] = {r, c};
        
        vector<int> paintedRows(m, 0), paintedColumns(n, 0);
        for (int i = 0; i < arr.size(); ++i) 
        {
            auto [row, col] = valToPosition[arr[i]];
            
            ++paintedRows[row];
            ++paintedColumns[col];

            // Check if the row or column is completely painted
            if (paintedRows[row] == n || paintedColumns[col] == m)
                return i;
        }

        return -1;
    }
};
