class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(m+n)
    * Space Complexity : O(1)
    */
    int countNegatives(vector<vector<int>>& grid) 
    {
        int count{}, row = 0, col = grid[0].size()-1, m = (int)grid.size();
        
        while(col >= 0 && row < m)
        {
            if(grid[row][col] < 0)
                count += m-row, col--;
            else
                row++;
        }
        return count;  
    }
};