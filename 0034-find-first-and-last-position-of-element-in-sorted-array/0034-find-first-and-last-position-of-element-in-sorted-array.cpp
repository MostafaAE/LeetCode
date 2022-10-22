class Solution {
public:
    /* 
    * Approach:
    * binary search: find the lower bound and upper bound of the target
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int start{-1}, end{-1};
        auto p = equal_range(nums.begin(), nums.end(), target);
        
        // found
        if(p.first != p.second)
        {
            start = p.first - nums.begin();
            end = p.second - nums.begin() - 1;
        }
            
        return {start, end};
        
    }
};