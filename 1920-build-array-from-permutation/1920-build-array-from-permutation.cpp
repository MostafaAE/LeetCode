/*
 * Approach:
 * We are asked to construct an array `ans` such that `ans[i] = nums[nums[i]]`
 * but we must do this without using extra space (in-place).
 * 
 * To achieve this:
 * - We encode both the original and target values into each `nums[i]` using modular arithmetic.
 * - We use a large enough `maxVal` (greater than all possible `nums[i]` values) so we can decode both later.
 * - Specifically, we set:
 *     nums[i] = nums[i] + maxVal * (nums[nums[i]] % maxVal)
 *   Now `nums[i] / maxVal` gives the new value, and `nums[i] % maxVal` gives the old value.
 * - Finally, we update each number by extracting the new value via integer division.

 * Time Complexity  : O(n)
 * Space Complexity : O(1) — in-place modification, no extra space used
 */

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) 
    {
        int n = (int)nums.size(), maxVal = 1000;

        // Encode both original and target values into nums[i]
        for(int i = 0 ; i < n ; i++)
        {
            nums[i] += maxVal * (nums[nums[i]] % maxVal);
        }

        // Extract the new values
        for(int& num : nums)
        {
            num /= maxVal;
        }

        return nums;
    }
};
