/*
 * Approach:
 * - Initialize a result array of size `nums.size()` filled with 1s (representing all odd values).
 * - Traverse the input `nums`:
 *     - If the number is even, place a 0 at the current `left` index of the result.
 *     - Increment the `left` pointer to move to the next position for a zero.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1), ignoring output space
 */

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) 
    {
        int left = 0;
        vector<int> result(nums.size(), 1); // Initialize all values as 1 (odd)

        for (int num : nums)
        {
            // If number is even, assign 0 at the front part of the array
            if (!(num & 1))
                result[left++] = 0;
        }

        return result;
    }
};