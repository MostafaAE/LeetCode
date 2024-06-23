class Solution {
public:
    /*
    * Approach:
    * - Use a sliding window technique and maintain a multiset to store the elements of the current window. The multiset allows us to quickly get the minimum and maximum values in the window.
    * - Expand the window by moving the right pointer. If the condition (max - min <= limit) is violated, shrink the window by moving the left pointer.
    * 
    * Complexity:
    * - Time Complexity: O(n logn)
    * - Space Complexity: O(n)
    */
    int longestSubarray(vector<int>& nums, int limit) 
    {
        int n = nums.size(), maxSoFar = 0;
        multiset<int> window;
        
        // Initialize two pointers for the sliding window
        for(int right = 0, left = 0; right < n; ++right)
        {
            window.insert(nums[right]);
            
            // While the condition is violated, shrink the window from the left
            while(*window.rbegin() - *window.begin() > limit)
                window.erase(window.find(nums[left++]));
                  
            maxSoFar = max(maxSoFar, right - left + 1);
        }
        
        return maxSoFar;
    }
};
