/*
 * Approach:
 * - Variant of Kadane's Algorithm.
 * - Track maximum subarray sum (`curMaxSum`) and minimum subarray sum (`curMinSum`) as we iterate.
 * - The answer is the maximum of absolute value of minSum and maxSum.
 * 
 * Time Complexity : O(n), where n = size of nums.
 * Space Complexity: O(1), constant space.
 */

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int maxSum = 0, minSum = 0;
        int curMaxSum = 0, curMinSum = 0;

        for (int num : nums)
        {
            curMaxSum += num;
            curMaxSum = max(curMaxSum, 0);

            curMinSum += num;
            curMinSum = min(curMinSum, 0);

            maxSum = max(maxSum, curMaxSum);
            minSum = min(minSum, curMinSum);
        }

        return max(maxSum, abs(minSum));
    }
};