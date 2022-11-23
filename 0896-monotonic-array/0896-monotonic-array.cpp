class Solution {
public:
    /* 
    * Approach:
    * Iterate over the array, and check if every two numbers are increasing or decreasing
    * if the array is both increasing and decreasing then it is not monotonic
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    bool isMonotonic(vector<int>& nums) 
    {
        bool increasing{}, decreasing{};
        
        for(int i = 1 ; i < (int)nums.size() ; i++)
        {
            if(nums[i]-nums[i-1] > 0)
                increasing = 1;
            else if(nums[i] - nums[i-1] < 0)
                decreasing = 1;
            
            if(increasing && decreasing)
                return false;
        }
        
        return true;
    }
};