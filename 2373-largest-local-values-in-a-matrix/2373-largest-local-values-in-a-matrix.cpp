class Solution {
public:
    /* 
    * Approach:
    * - For each cell, find the maximum value in its 3x3 local neighborhood.
    *
    * Complexity:
    * - Time Complexity: O(n^2), where n is the size of the grid.
    * - Space Complexity: O(1), ignoring output space.
    */
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> result(n-2, vector<int>(n-2));
        
        for(int i = 0 ; i < n-2 ; ++i)
            for(int j = 0 ; j < n-2 ; ++j)
                result[i][j] = getMax(grid, i+1, j+1);
        
        return result;
    }
    
    // Get maximum value in the 3x3 local neighborhood of a cell
    int getMax(vector<vector<int>>& grid, int r, int c)
    {
        int maxVal{INT_MIN};
        
        for(int i = -1 ; i <= 1 ; ++i)
            for(int j = -1 ; j <= 1 ; ++j)
                maxVal = max(maxVal, grid[r+i][c+j]);
        
        return maxVal;
    }
};