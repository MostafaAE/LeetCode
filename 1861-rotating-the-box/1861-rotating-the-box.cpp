class Solution {
public:
    /**
     * Approach:
     * 1. **Simulate Gravity**:
     *    - Iterate over each row in the `box` from right to left.
     *    - Stones (`#`) fall to the lowest available position (tracked by `lowestColWithEmptyCell`).
     *    - When an obstacle (`*`) is encountered, reset `lowestColWithEmptyCell` to just before the obstacle.
     * 2. **Rotate the Box**:
     *    - Create a new 2D vector `rotatedBox` with dimensions `cols x rows`.
     *    - Map each cell in the `box` to its new position in `rotatedBox` such that the box is rotated 90° clockwise.
     *
     * Complexity:
     * Time Complexity: O(m * n)
     * - Simulating gravity for each cell takes O(m * n).
     * - Rotating the box involves iterating through all cells, which is also O(m * n).
     * Space Complexity: O(m * n)
     */
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        int rows = box.size(), cols = box[0].size();
        
        vector<vector<char>> rotatedBox(cols, vector<char>(rows));
        
        for(int r = 0 ; r < rows ; ++r)
        {
            int lowestColWithEmptyCell = cols - 1;
            for(int c = cols - 1 ; c >= 0 ; --c)
            {
                if(box[r][c] == '#')
                {
                    box[r][c] = '.';
                    box[r][lowestColWithEmptyCell] = '#';
                    --lowestColWithEmptyCell;
                }
                
                if(box[r][c] == '*')
                    lowestColWithEmptyCell = c - 1;
            }
        }
        
        for(int r = 0 ; r < rows ; ++r)
            for(int c = 0 ; c < cols ; ++c)
                rotatedBox[c][rows - r - 1] = box[r][c];
        
        return rotatedBox;
    }
    
    
};