/*
 * Approach:
 * - Traverse the array while identifying consecutive ranges.
 * - Use a `start` index to track the beginning of the current range.
 * - When a break in the sequence is found (or end is reached):
 *   - If it's a single number, add it as is.
 *   - If it's a range, format it as "start->end".
 * - Update `start` to the next new range.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1), ignoring output space
 */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> result;
        int n = nums.size(), start = 0;

        for (int i = 1; i <= n; ++i) 
        {
            // If we're at the end or the sequence is broken
            if (i == n || nums[i] != nums[i - 1] + 1) 
            {
                if (start == i - 1)
                {
                    // Single number range
                    result.push_back(to_string(nums[start]));
                }
                else
                {
                    // Range with multiple numbers
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
                }

                start = i;
            }
        }

        return result;
    }
};