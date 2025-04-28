/**
 * Approach:
 * - Use the sliding window technique.
 * - Maintain a window [left, right] such that sum of the window * window size < k.
 * - If the condition is violated, move the left pointer to shrink the window.
 * - For each valid right, add (right - left + 1) to the answer, 
 *   because all subarrays ending at right and starting from left to right are valid.
 * 
 * Time Complexity: O(n)
 *   - Each element is visited at most twice (once by right, once by left).
 * Space Complexity: O(1)
 */

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        int n = nums.size();
        long long count = 0, sum = 0;

        for (int right = 0, left = 0; right < n; ++right)
        {
            sum += nums[right];

            while (sum * (right - left + 1) >= k && left <= right)
            {
                sum -= nums[left];
                ++left;
            }

            count += right - left + 1;
        }

        return count;
    }
};