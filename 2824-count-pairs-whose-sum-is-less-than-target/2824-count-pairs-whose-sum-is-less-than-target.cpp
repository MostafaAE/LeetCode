/*
 * Approach:
 * - Sort the array to allow two-pointer technique.
 * - Use two pointers (left and right) to find how many pairs (left, right) satisfy the condition:
 *   nums[left] + nums[right] < target
 * - If the condition is met:
 *     -> All elements from left to right-1 can form valid pairs with nums[left], so we add (right - left) to count.
 *     -> Move left forward to check for the next potential pair.
 * - If the condition is not met, decrement right to reduce the sum.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int countPairs(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());

        int left = 0, right = (int)nums.size() - 1;
        int count = 0;

        while (left < right)
        {
            // If the sum is less than target, all pairs (left, left+1)...(left, right) are valid
            if (nums[left] + nums[right] < target)
            {
                count += right - left;
                ++left;
            }
            else
            {
                --right; // Try a smaller right element to decrease the sum
            }
        }

        return count;
    }
};