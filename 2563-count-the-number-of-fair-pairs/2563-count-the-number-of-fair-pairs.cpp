/**
 * Approach:
 * - We're given an array and need to count how many pairs (i, j) exist (i < j)
 *   such that the sum of nums[i] + nums[j] is between [lower, upper].
 * 
 * - Steps:
 *   1. Sort the array to allow binary search.
 *   2. For each element nums[i], use binary search to find:
 *      - the first index `idx1` such that nums[i] + nums[j] >= lower  → lower_bound.
 *      - the first index `idx2` such that nums[i] + nums[j] > upper   → upper_bound.
 *   3. The number of valid pairs for this i is (idx2 - idx1),
 *      but we ensure idx1 > i to satisfy i < j.
 * 
 * - We accumulate the count of all valid (i, j) pairs this way.
 * 
 * Time Complexity: O(N log N)
 * - Sorting takes O(N log N).
 * - For each of the N elements, we do two binary searches → O(log N).
 * 
 * Space Complexity: O(1) extra space (excluding input).
 */

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        int n = nums.size();
        long long result = 0;

        // Step 1: Sort the array to enable binary search
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through each index
        for (int i = 0; i < n; ++i)
        {
            // Find the lower bound for (lower - nums[i])
            auto lb = lower_bound(nums.begin(), nums.end(), lower - nums[i]);

            // Find the upper bound for (upper - nums[i])
            auto up = upper_bound(nums.begin(), nums.end(), upper - nums[i]);

            // Convert iterators to indices
            int idx1 = lb - nums.begin();
            int idx2 = up - nums.begin();

            // Ensure we don't count (i, j) where j <= i
            if (idx1 <= i)
                idx1 = i + 1;

            // Accumulate valid pairs count
            result += max(idx2 - idx1, 0);
        }

        return result;
    }
};