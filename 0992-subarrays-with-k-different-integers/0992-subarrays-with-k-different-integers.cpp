class Solution {
public:
    /* 
    * Approach:
    * Sliding window technique
    * 1. Count the number of subarrays with at most k distinct integers.
    * 2. Count the number of subarrays with at most (k-1) distinct integers.
    * 3. Subtract 2 from 1 to get the number of subarrays with exactly k distinct integers.
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return slidingWindowAtMost(nums, k) - slidingWindowAtMost(nums, k-1);
    }
    
private:
    // Helper function to count the number of subarrays with at most k distinct elements.
    int slidingWindowAtMost(vector<int>& nums, int distinctK)
    {
        int n{(int)nums.size()}, res{};
        unordered_map<int, int> count;
        
        for(int right = 0, left = 0 ; right < n ; right++)
        {
            count[nums[right]]++;
            
            // If the number of distinct elements in the window exceeds k,
            // we shrink the window from the left until we have at most k distinct elements.
            while(count.size() > distinctK)
            {
                count[nums[left]]--;
                if(count[nums[left]] == 0)
                    count.erase(nums[left]);
                left++;
            }
            
            // Update the total count by adding the length of the current subarray.
            res += right - left + 1;
        }
        return res;
    }
};