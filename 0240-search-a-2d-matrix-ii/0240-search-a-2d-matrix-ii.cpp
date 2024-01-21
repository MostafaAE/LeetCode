class Solution {
public:
    /* 
    * Approach:
    * binary search each row for the target value
    * 
    * Complexity:
    * Time Complexity : O(mlogn)
    * Space Complexity : O(1)
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m{(int)matrix.size()}, n{(int)matrix[0].size()};
        
        for(int i = 0 ; i < m ; i++)
            if(binarySearchRow(matrix, target, i))
                return true;
        
        return false;
        
    }
    
    bool binarySearchRow(vector<vector<int>>& matrix, int target, int row)
    {
        int start{}, end{(int)matrix[0].size() -1};
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if(target == matrix[row][mid])
                return true;
            if(target < matrix[row][mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }    
};