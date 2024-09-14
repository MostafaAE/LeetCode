class Solution {
public:
    /**
     * Approach:
     * - Traverse the array to find the maximum value in `nums`.
     * - Keep track of the length of the longest contiguous subarray consisting of this maximum value.
     * - Each time a new maximum is found, reset the length counter and update the maximum value.
     * - If the current element equals the maximum value, increase the length of the current subarray.
     * - If not, reset the current subarray length to zero.
     * - Return the length of the longest subarray found that contains the maximum Bitwise AND.
     * 
     * Complexity:
     * - Time Complexity: O(n), where `n` is the size of the `nums` array.
     * - Space Complexity: O(1)
     */
    int longestSubarray(vector<int>& nums) 
    {
        int n = nums.size(), maxVal{}, maxLen{}, maxSoFar{};
        
        for(int i = 0 ; i < n ; ++i)
        {                
            if(nums[i] > maxVal)
            {
                maxVal = nums[i];
                maxLen = 0;
                maxSoFar = 0;
            }

            if(nums[i] == maxVal)
                ++maxSoFar;
            else
                maxSoFar = 0;
            
            maxLen = max(maxLen, maxSoFar);
        }
        
        return maxLen;
    }
};