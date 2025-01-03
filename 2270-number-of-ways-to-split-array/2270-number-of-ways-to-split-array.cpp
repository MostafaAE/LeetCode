class Solution {
public:
    /**
     * Approach:
     * - Use prefix sums to calculate the sum of the left and right parts of the array efficiently.
     * - For each split point `i`, calculate:
     *     - Left sum: `prefix[i]`
     *     - Right sum: `prefix[n-1] - prefix[i]`
     * - If the left sum is greater than or equal to the right sum, increment the result.
     *
     * Complexity:
     * Time Complexity: O(n)
     * - Computing prefix sum: O(n), where `n` is the size of the array.
     * - Iterating through the array to count valid splits: O(n).
     * Space Complexity: O(n) for the prefix sum array.
     */
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), result = 0;
        vector<long long> prefix(n, 0);

        // Compute the prefix sum array
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + nums[i];

        // Check valid splits
        for (int i = 0; i < n - 1; ++i)
            if (prefix[i] >= prefix[n - 1] - prefix[i])
                ++result;

        return result;
    }
};
