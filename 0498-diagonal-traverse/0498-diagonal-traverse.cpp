class Solution 
{
public:
    /*
    * Approach:
    * - We need to traverse a matrix diagonally in a zig-zag pattern:
    *     1. Start from (0,0).
    *     2. Move diagonally up-right (row--, col++) when direction = 1.
    *     3. Move diagonally down-left (row++, col--) when direction = 0.
    *     4. When hitting a boundary (top, bottom, left, or right), 
    *        adjust the row/col to the next valid starting position and flip direction.
    * - Continue until all elements are visited.
    *
    * Time Complexity: O(m * n)
    * Space Complexity: O(1)
    */
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        int row = 0, col = 0;
        int direction = 1;          // 1 = up-right, 0 = down-left
        vector<int> result;

        while (row < m && col < n)
        {            
            result.push_back(mat[row][col]);

            // Compute next cell in current diagonal direction
            int newRow = row + (direction == 1 ? -1 : 1);
            int newCol = col + (direction == 1 ?  1 : -1);

            // If out of bounds - need to move to next valid edge and flip direction
            if (newRow < 0 || newRow == m || newCol < 0 || newCol == n)
            {
                if (direction == 1) // Moving up-right
                {
                    // If at last column, move down; otherwise move right
                    row += (col == n - 1 ? 1 : 0);
                    col += (col < n - 1 ? 1 : 0);
                }
                else // Moving down-left
                {
                    // If at last row, move right; otherwise move down
                    col += (row == m - 1 ? 1 : 0);
                    row += (row < m - 1 ? 1 : 0);
                }

                // Flip direction
                direction = 1 - direction;
            }
            else
            {
                // Stay within bounds → continue diagonal movement
                row = newRow;
                col = newCol;
            }
        }

        return result;
    }
};
