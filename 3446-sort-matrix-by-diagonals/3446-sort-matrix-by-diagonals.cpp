class Solution 
{
public:
    /*
    * Approach:
    * - We need to sort:
    *   1. Each top-right diagonal (starting from row 0, col i) in ascending order.
    *   2. Each bottom-left diagonal (starting from col 0, row i) in descending order.
    *
    * Steps:
    * - Iterate over diagonals starting from the first row and first column.
    * - Collect elements of each diagonal into temporary arrays `topRight` and `bottomLeft`.
    * - Sort `topRight` in ascending order and `bottomLeft` in descending order.
    * - Place the sorted values back into their respective diagonal positions in `result`.
    *
    * Time Complexity: O(n^2 log n)
    * Space Complexity: O(n)
    */
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> result(grid);
        
        for (int i = 0; i < n - 1; ++i)
        {
            vector<int> topRight, bottomLeft;

            int r = 0, c = i;

            // Collect elements from both diagonals
            for (int j = 0; j < n - i; ++j)
            {
                topRight.push_back(grid[r + j][c + j]);
                bottomLeft.push_back(grid[c + j][r + j]);
            }

            // Sort top diagonal ascending, bottom diagonal descending
            sort(topRight.begin(), topRight.end());
            sort(bottomLeft.begin(), bottomLeft.end(), greater<>());

            // Place back sorted values
            for (int j = 0; j < n - i; ++j)
            {
                result[r + j][c + j] = topRight[j];
                result[c + j][r + j] = bottomLeft[j];
            }
        }

        return result;
    }
};