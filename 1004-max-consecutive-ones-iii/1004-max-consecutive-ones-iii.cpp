/*
 * Approach:
 * - Sliding Window
 * - Maintain a window [left, right] where at most `k` zeros are flipped to ones.
 * - Move the right pointer to expand the window.
 * - If zeros in the window exceed k, move left pointer to shrink window until zerosCount <= k.
 * - At each step, update the maximum window length.
 *
 * Time Complexity : O(n), where n = size of nums.
 * Space Complexity: O(1), only constant extra space used.
 */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int zerosCount = 0, result = 0;

        for (int right = 0, left = 0; right < (int)nums.size(); ++right) 
        {
            zerosCount += (nums[right] == 0);            

            while (zerosCount > k) 
            {
                zerosCount -= (nums[left] == 0);
                ++left;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};