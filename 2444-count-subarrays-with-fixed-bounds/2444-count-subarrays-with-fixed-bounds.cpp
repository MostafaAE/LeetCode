class Solution {
public:
    /* 
    * Approach:
    * Sliding window technique (3 pointers):
    * 1. Move over the array if we found value < minK || value > maxK, mark it as new subarray start index
    * 2. if we found value == minK, mark it as the latest min index
    * 3. if we found value == maxK, mark it as the latest max index
    * 4. for each iteration we calculate the subarrays count `max(0L, min(lastestMinIdx, latestMaxIdx) - subArrayStartIndex)`
    *
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        long count = 0, subArrayStartIndex = -1, lastestMinIdx = -1, latestMaxIdx = -1, n = nums.size();
        
        for (int i = 0 ; i < n ; ++i) 
        {
            if (nums[i] < minK || nums[i] > maxK) 
                subArrayStartIndex = i;
            
            if (nums[i] == minK) 
                lastestMinIdx = i;
            
            if (nums[i] == maxK) 
                latestMaxIdx = i;
            
            count += max(0L, min(lastestMinIdx, latestMaxIdx) - subArrayStartIndex);
        }
        
        return count;
    }
};