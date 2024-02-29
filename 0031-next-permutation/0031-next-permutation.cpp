class Solution {
public:
    /* 
    * Approach: 
    * Get the length of the longest decreasing suffix subarray, then swap the next number to it with its successor from longest decreasing suffix subarray, then sort the longest decreasing suffix subarray (reverse).
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    void nextPermutation(vector<int>& nums) 
    {
        int sz{(int)nums.size()}, i = sz - 2, j = sz - 1;
        
        // get the length of the consecutive decreasing suffix
        while(i >= 0 && nums[i] >= nums[i + 1])
            i--;
        
        if(i == -1)
            return reverse(nums.begin(), nums.end());
        
        while(j > i && nums[i] >= nums[j])
            j--;
        
        swap(nums[j], nums[i]);
            
        return reverse(nums.begin() + i + 1, nums.end());
    }
};