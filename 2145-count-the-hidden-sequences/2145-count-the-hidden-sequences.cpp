/**
 * Approach:
 * - We are given the difference between consecutive elements of an array.
 * - We want to reconstruct all possible arrays that stay within [lower, upper].
 * 
 * - Let the first element be `x`. Then the rest of the array is determined by the prefix sums of `differences`.
 * - We compute the minimum and maximum prefix sum of differences.
 * - To keep the entire array in the range [lower, upper], `x` must be chosen such that:
 *      lower <= x + minPrefix
 *      upper >= x + maxPrefix
 *   --> which means: lower - minPrefix <= x <= upper - maxPrefix
 * 
 * - So the number of valid values of `x` is:
 *      (upper - lower + 1) - (maxPrefix - minPrefix)
 * 
 * Time Complexity: O(N) — single pass to compute prefix sums.
 * Space Complexity: O(1) — only constant extra space is used.
 */

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) 
    {
        long long minPrefix = 0, maxPrefix = 0, prefixSum = 0;

        // Compute min and max prefix sum to determine the range shift
        for (int val : differences)
        {
            prefixSum += val;
            minPrefix = min(minPrefix, prefixSum);
            maxPrefix = max(maxPrefix, prefixSum);
        }

        // Calculate the number of valid starting values that keep the sequence in bounds
        int diff = maxPrefix - minPrefix;
        int result = upper - lower + 1 - diff;

        return max(0, result);
    }
};
