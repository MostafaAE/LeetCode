class Solution {
public:
    /**
     * Approach:
     * - Count the number of inversions (where nums[i] < nums[i-1]).
     * - Check the last element against the first to account for circularity.
     * - If there is at most one inversion, the array can be rotated to become sorted.
     *
     * Complexity:
     * - Time: O(n), where n is the size of the array.
     * - Space: O(1).
     */
    bool check(vector<int>& nums) 
    {
        int n = nums.size();
        if (n <= 1) 
            return true; // Single element or empty array is always sorted.

        int inversionCount = 0;

        // Count inversions in the array
        for (int i = 1; i < n; ++i) 
        {
            if (nums[i] < nums[i - 1]) 
                ++inversionCount;
        }

        // Check the last element against the first for circular rotation
        if (nums[0] < nums[n - 1])
            ++inversionCount;

        // The array is valid if there is at most one inversion
        return inversionCount <= 1;
    }
};
