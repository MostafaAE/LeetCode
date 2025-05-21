class Solution {
public:
    /*
     * Approach:
     * In-Place Marker Strategy using First Row and Column
     *
     * We use the first row and first column to mark which rows and columns need to be zeroed.
     * Additionally, we keep two flags to remember if the first row or first column should be zeroed.
     * This avoids using extra space beyond a few variables (O(1) space).
     *
     * Time Complexity : O(m * n)
     * Space Complexity : O(1)
     */
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // First pass: mark zeros in the first row and column
        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    // If the zero is in the first row or column, remember to zero them at the end
                    if(i == 0)
                        firstRowZero = true;
                    if(j == 0)
                        firstColZero = true;

                    // Mark the corresponding row and column to be zeroed
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Second pass: zero out cells based on markers, skipping first row and column
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Zero out the first row if needed
        if(firstRowZero)
        {
            for(int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        }

        // Zero out the first column if needed
        if(firstColZero)
        {
            for(int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
    }
};