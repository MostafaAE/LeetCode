class Solution {
public:
    /**
     * Approach:
     * 1. Use a sliding window technique to process the `nums` array with a window of size `k`.
     * 2. Maintain indices `left` and `right` to represent the window's boundaries.
     * 3. Track the `lastNonConsecutiveIdx` where a non-consecutive number was found within the window.
     *    - If the difference between `nums[right]` and `nums[right-1]` is not 1, update `lastIdx` to `right`.
     * 4. For each window:
     *    - If the window is valid (no non-consecutive numbers from `left` to `right`), add `nums[right]` to the result.
     *    - Otherwise, add `-1` to the result.
     * 5. Slide the window by incrementing both `left` and `right`.
     * 
     * Time Complexity: O(n), where n is the size of the `nums` array.
     * Space Complexity: O(1)
     */
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        int left{}, right{0}, lastNonConsecutiveIdx{-1};
        vector<int> result;

        // Initialize the window up to size k-1
        while(right < k-1)
        {
            if(right > 0 && nums[right] - nums[right-1] != 1)
                lastNonConsecutiveIdx = right;
            ++right;
        }

        // Process the rest of the array using a sliding window
        while(right < nums.size())
        {
            if(right > 0 && nums[right] - nums[right-1] != 1)
                lastNonConsecutiveIdx = right;

            if(lastNonConsecutiveIdx <= left)
                result.push_back(nums[right]); // Valid window
            else
                result.push_back(-1); // Invalid window

            ++right, ++left; // Slide the window
        }

        return result;
    }
};
