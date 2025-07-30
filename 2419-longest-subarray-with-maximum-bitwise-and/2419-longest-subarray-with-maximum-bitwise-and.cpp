/*
 * Approach:
 * - Traverse the array once while keeping track of:
 *   - The maximum value `maxVal` found so far.
 *   - A counter `maxLengthSoFar` to track the length of the current subarray of max elements.
 *   - A variable `maxLength` to track the longest such subarray seen so far.
 * - If a new maximum is found, reset both counters.
 * - If the current number equals the max value, increment the counter.
 * - Otherwise, reset the counter to zero.
 * - Update the `maxLength` with the maximum of itself and the current streak length.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxValue = 0, maxLength = 0, maxLengthSoFar = 0;

        for (int num : nums)
        {
            // If we find a new maximum value, reset tracking
            if (num > maxValue)
            {
                maxValue = num;
                maxLength = 0;
                maxLengthSoFar = 0;
            }

            // Count current streak of max values
            if (num == maxValue)
                ++maxLengthSoFar;
            else
                maxLengthSoFar = 0;

            maxLength = max(maxLength, maxLengthSoFar);
        }

        return maxLength;
    }
};