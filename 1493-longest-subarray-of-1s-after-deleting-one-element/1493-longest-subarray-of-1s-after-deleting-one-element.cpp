class Solution 
{
public:
    /*
    * Approach:
    * - Sliding window (two pointers) approach:
    *     1. Keep a window [left, right] that contains at most one zero.
    *     2. Expand the window by moving `right`.
    *     3. If the window has more than one zero, shrink it from the left.
    *     4. The length of a valid subarray = (right - left), because one zero must be deleted.
    * - Track the maximum length during iteration.
    *
    * Time Complexity: O(n)
    * Space Complexity: O(1)
    */
    int longestSubarray(vector<int>& nums) 
    {
        int left = 0, n = nums.size();
        int zerosCount = 0;
        int longest = 0;

        for (int right = 0; right < n; ++right)
        {
            // Expand window: include nums[right]
            zerosCount += (nums[right] == 0);

            // If more than one zero, shrink window from the left
            while (zerosCount > 1)
            {
                zerosCount -= (nums[left] == 0);
                ++left;
            }

            // Valid window has at most one zero
            // Subarray length = right - left (not +1, because we must delete one zero)
            longest = max(longest, right - left);
        }

        return longest;
    }
};