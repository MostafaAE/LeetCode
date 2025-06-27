/*
 * Approach:
 * - Sort the input array to simplify duplicate handling and enable the two-pointer technique.
 * - Iterate over the array with index `i`:
 *     - Skip duplicates to avoid repeating triplets.
 *     - Use two pointers (`start`, `end`) to find two numbers such that:
 *         nums[i] + nums[start] + nums[end] == 0
 *     - Move `start` and `end` accordingly based on the sum.
 *     - After finding a valid triplet, skip duplicates on both pointers to avoid duplicate results.
 *
 * Time Complexity  : O(n^2), where n is the size of the input array.
 * Space Complexity : O(1), excluding the space required for the result.
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = (int)nums.size();
        vector<vector<int>> result;

        // Sort the array to apply the two-pointer technique
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i)
        {
            // Skip duplicate values
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i];
            int start = i + 1, end = n - 1;

            while (start < end)
            {
                int sum = nums[start] + nums[end];

                if (sum == target)
                {
                    result.push_back({nums[i], nums[start], nums[end]});

                    ++start;
                    // Skip duplicate values
                    while (start < end && nums[start] == nums[start - 1])
                        ++start;

                    --end;
                    // Skip duplicate values
                    while (start < end && nums[end] == nums[end + 1])
                        --end;
                }
                else if (sum < target)
                {
                    ++start;
                }
                else
                {
                    --end;
                }
            }
        }

        return result;
    }
};