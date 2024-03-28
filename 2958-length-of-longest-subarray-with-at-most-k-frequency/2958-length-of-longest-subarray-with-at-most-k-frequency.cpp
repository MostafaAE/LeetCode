class Solution {
public:
    /* 
    * Approach:
    * We use a sliding window technique to find the longest subarray where each number appears at most k times.
    * As we move the window to the right, we track how many times each number appears.
    * If any number appears more than k times, we shrink the window from the left until it meets the frequency requirement.
    * We update the longest subarray length encountered during this process.
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq;
        int maxLen{};
        
        for(int right = 0, left = 0 ; right < (int)nums.size() ; right++)
        {
            freq[nums[right]]++;
            
            while(freq[nums[right]] > k)
                freq[nums[left++]]--;
            
            maxLen = max(maxLen, right-left+1);
        }
        
        return maxLen;
    }
};