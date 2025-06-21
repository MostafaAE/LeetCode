/*
 * Approach:
 * - Kadane's Algorithm
 * - Iterate through the array, at each step:
 *     - Decide whether to continue the current subarray or start a new one.
 *     - Keep track of the maximum subarray sum seen so far.
 *
 * Time Complexity : O(n), where n = size of nums.
 * Space Complexity: O(1), only constant extra space used.
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxSoFar = INT_MIN, maxEndingHere = 0;
        
        for (int val : nums) 
        {
            maxEndingHere = max(maxEndingHere, 0);
            maxEndingHere += val;
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
    }
};