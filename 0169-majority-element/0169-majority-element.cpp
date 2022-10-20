class Solution {
public:
    /* 
    * Approach:
    * Sort the array and return the middle element, since the majority element appears more
    * than (n/2)
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        return nums[nums.size()/2];
        
        return 0;
    }
};