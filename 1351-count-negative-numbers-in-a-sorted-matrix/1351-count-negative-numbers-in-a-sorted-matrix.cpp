class Solution {
public:
    /* 
    * Approach:
    * Binary search each row for the smallest +ve value to get the -ve numbers in that row
    *
    * Complexity:
    * Time Complexity : O(mlogn)
    * Space Complexity : O(1)
    */
    int countNegatives(vector<vector<int>>& grid) 
    {
        int count{}, m = (int)grid.size();
        
        for(int i = 0 ; i < m ; i++)
        {
            auto ub = upper_bound(grid[i].rbegin(), grid[i].rend(), -1);
            count += ub - grid[i].rbegin();
        }
        
        return count;  
    }
};