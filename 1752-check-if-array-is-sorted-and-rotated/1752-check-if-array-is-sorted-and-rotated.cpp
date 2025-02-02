class Solution {
public:
    /**
     * Approach:
     * - Find the index where the order breaks (`nums[i] < nums[i-1]`).
     * - Validate that the rest of the array is sorted circularly starting from the breakpoint.
     *
     * Complexity:
     * - Time: O(n), where n is the size of the array.
     * - Space: O(1).
     */
    bool check(vector<int>& nums) 
    {
        int startIdx = 0, n = nums.size();

        // Find the first "break" point
        for (int i = 1; i < n; ++i) 
        {
            if (nums[i] < nums[i - 1]) 
            {
                startIdx = i;
                break;
            }
        }

        // If no break point is found, the array is already sorted
        if (startIdx == 0)
            return true;

        // Validate that the array is sorted circularly starting from the break point
        for (int i = 1; i < n; ++i) 
        {
            int cur = (startIdx + i) % n;
            int prev = (startIdx + i - 1) % n;

            if (nums[cur] < nums[prev]) 
                return false;
        }

        return true;
    }
};
