/*
 * Approach:
 * - Modified Kadane’s Algorithm for circular subarray.
 * - There are 2 cases:
 *   1. Max subarray is a normal subarray — use regular Kadane’s to compute maxSum.
 *   2. Max subarray is circular — totalSum - minSum gives the max circular sum.
 * - If all elements are negative, totalSum == minSum → in this case return maxSum (avoids empty subarray).
 *
 * Time Complexity : O(n), where n = size of nums.
 * Space Complexity: O(1), constant space.
 */

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int maxSum = INT_MIN, minSum = INT_MAX, totalSum = 0;
        int curMaxSum = 0, curMinSum = 0;

        for (int num : nums)
        {
            curMaxSum += num;
            curMinSum += num;

            maxSum = max(maxSum, curMaxSum);
            minSum = min(minSum, curMinSum);

            curMaxSum = max(curMaxSum, 0);
            curMinSum = min(curMinSum, 0);

            totalSum += num;
        }

        // All elements negative → totalSum == minSum
        if (totalSum == minSum)
            return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};