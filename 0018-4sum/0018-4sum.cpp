/*
 * Approach:
 * - Sort the input array to simplify duplicate handling and allow two-pointer traversal.
 * - Use two nested loops to fix the first two elements (i, j).
 * - For the remaining subarray (from j+1 to end), use the two-pointer technique to find two numbers that
 *   sum up to the required target minus nums[i] and nums[j].
 * - Use long long to prevent integer overflow when computing the remaining goal.
 * - Skip duplicate elements at each step to avoid duplicate quadruplets.
 *
 * Time Complexity  : O(n^3), where n is the number of elements in the array.
 *                    - Outer loop: O(n)
 *                    - Second loop: O(n)
 *                    - Two-pointer scan: O(n)
 *                    => Total: O(n^3)
 *
 * Space Complexity : O(1) excluding the output.
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<vector<int>> result;

        // Sort the array to use two pointers and skip duplicates
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i)
        {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; ++j)
            {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                long long goal = (long long)target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;

                while (left < right)
                {
                    int sum = nums[left] + nums[right];

                    if (sum == goal)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        ++left;
                        --right;

                        // Skip duplicates for the third and fourth elements
                        while (left < right && nums[left] == nums[left - 1])
                            ++left;
                        while (left < right && nums[right] == nums[right + 1])
                            --right;
                    }
                    else if (sum < goal)
                    {
                        ++left;
                    }
                    else
                    {
                        --right;
                    }
                }
            }
        }

        return result;
    }
};