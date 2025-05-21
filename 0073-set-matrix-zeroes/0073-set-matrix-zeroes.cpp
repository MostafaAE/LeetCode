class Solution {
public:
    /*
     * Approach:
     * Use two hash sets to keep track of which rows and columns need to be set to zero.
     * 
     * First pass:
     * - Identify all rows and columns that contain at least one zero.
     * 
     * Second pass:
     * - Set all cells in the identified rows and columns to zero.
     *
     * Complexity:
     * Time Complexity  : O(M * N) — where M = rows, N = columns of the matrix.
     * Space Complexity : O(M + N) — additional space for row and column sets.
     */
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> rows, cols;

        // First pass: record rows and columns containing zero
        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        // Second pass: zero out recorded rows
        for(int r : rows)
        {
            for(int c = 0 ; c < n ; ++c)
            {
                matrix[r][c] = 0;
            }
        }

        // Second pass: zero out recorded columns
        for(int c : cols)
        {
            for(int r = 0 ; r < m ; ++r)
            {
                matrix[r][c] = 0;
            }
        }
    }
};