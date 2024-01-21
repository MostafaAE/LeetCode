class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(m+n)
    * Space Complexity : O(1)
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m{(int)matrix.size()}, n{(int)matrix[0].size()};
        
        int row{}, col{n-1};
        
        while(row < m && col > -1)
        {
            if(target == matrix[row][col])
                return true;
            
            if(target < matrix[row][col])
                col--;
            else
                row++;
        }
        
        return false;
        
    }
};