/**
 * Approach:
 * - We're given differences between consecutive elements of an unknown array.
 * - Let the first element be `x`. The rest of the elements are constructed using prefix sums of the differences.
 * - To ensure every value in the reconstructed array is in the range [lower, upper], we track:
 *      - minPrefix: the lowest value the prefix sum reaches
 *      - maxPrefix: the highest value the prefix sum reaches
 * - The range of values the array can reach becomes: [x + minPrefix, x + maxPrefix]
 * - We need this to fully fit inside [lower, upper], i.e.:
 *      (x + minPrefix) >= lower  AND  (x + maxPrefix) <= upper
 *      -> x in [lower - minPrefix, upper - maxPrefix]
 * 
 * - So the count of valid values for x is:
 *      (upper - lower + 1) - (maxPrefix - minPrefix)
 * - If the required difference exceeds the given bounds, return 0 early.
 * 
 * Time Complexity: O(N) — one pass through `differences`.
 * Space Complexity: O(1) — constant extra space.
 */

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) 
    {
        int minPrefix = 0, maxPrefix = 0, prefixSum = 0;

        // Track min and max prefix sum values
        for (int val : differences)
        {
            prefixSum += val;
            minPrefix = min(minPrefix, prefixSum);
            maxPrefix = max(maxPrefix, prefixSum);

            // Early exit if bounds are already exceeded
            if (maxPrefix - minPrefix > upper - lower)
                return 0;
        }

        // Compute valid starting values for the first element
        int result = upper - lower + 1 - (maxPrefix - minPrefix);

        return max(0, result);
    }
};
