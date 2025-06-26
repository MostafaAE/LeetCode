/*
 * Approach:
 * A "mountain" in the array is a subarray where there is a strictly increasing
 * sequence followed by a strictly decreasing sequence, with at least 3 elements total.
 *
 * We traverse the array while tracking two counters:
 * - `up`: counts increasing steps (ascending slope)
 * - `down`: counts decreasing steps (descending slope)
 *
 * If the current element is flat (equal to the previous) or if a new increasing 
 * sequence starts after a decreasing one, we reset both `up` and `down`.
 *
 * When we have both a non-zero `up` and a `down`, it forms a valid mountain,
 * and we update the result with the length of the current mountain: `up + down + 1`.
 *
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */

class Solution {
public:
    int longestMountain(vector<int>& nums) 
    {
        int n = nums.size();
        if(n < 3)
            return 0;

        int result = 0;
        int up = 0, down = 0;

        for(int i = 1 ; i < n ; ++i)
        {
            // Reset when the sequence flattens or a new climb starts after descent
            if((down && nums[i] > nums[i - 1]) || nums[i] == nums[i - 1])
            {
                up = down = 0;
            }

            // Count ascent and descent steps
            up += nums[i] > nums[i - 1];
            down += nums[i] < nums[i - 1];

            // A valid mountain must have both ascent and descent
            if(up && down)
            {
                result = max(result, up + down + 1);
            }
        }

        return result;
    }
};