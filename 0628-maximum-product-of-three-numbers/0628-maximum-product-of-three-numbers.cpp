class Solution {
public:
    /* 
    * Approach: 
    * Sort the array, then return the maximum product of 3 numbers (this could be the 3 largest +ve numbers or the 2 smallest -ve numbers and the largest +ve number).
    *
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    int maximumProduct(vector<int>& nums) 
    {
        int n{(int)nums.size()};
        
        // O(nlogn)
        sort(nums.begin(), nums.end());
        
        int prod1 = nums[n-1] * nums[n-2] * nums[n-3];
        int prod2 = nums[0] * nums[1] * nums[n-1];
        
        return max(prod1, prod2);
    }
};