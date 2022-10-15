class Solution {
public:
    /* 
    * Approach:
    * binary search the rows for a valid range, 
    * if there is a valid row then binary search the row for the target
    * 
    * Complexity:
    * Time Complexity : O(log(m*n)) ==> O(logm) + O(logn)
    * Space Complexity : O(1)
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        
        int start = 0, end = m-1;
        
        // search for a valid range for the target => O(logm)
        // Total time complexity = O(log(m) + log(n))
        while(start <= end)
        {
            int row = (start+end)/2;
            
            if(target < matrix[row][0])
                end = row-1;
            
            else if (target > matrix[row][n-1])
                start = row+1;
            
            else
            {
                // a valid row is found
                // use binary search to search for the target => O(logn)
                auto lb = lower_bound(matrix[row].begin(), matrix[row].end(), target);
                if(lb != matrix[row].end() && *lb == target)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
};