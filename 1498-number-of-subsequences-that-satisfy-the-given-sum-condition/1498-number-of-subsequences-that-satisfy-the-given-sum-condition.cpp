/*
 * Approach:
 * Given an array and a target, we want to count the number of non-empty subsequences
 * where the sum of the minimum and maximum elements is less than or equal to the target.
 *
 * Steps:
 * 1. Sort the array to efficiently find the valid range for each smallest element.
 * 2. Use two pointers:
 *    - `left` starts from 0, and `right` from the end of the array.
 *    - If nums[left] + nums[right] <= target, it means:
 *        -> all subsequences formed from elements between left and right (inclusive)
 *           that include nums[left] as the minimum and nums[right] as the maximum
 *           are valid. The number of such subsequences is 2^(right - left).
 *    - If the sum exceeds the target, we move the `right` pointer leftward to reduce the sum.
 * 3. Use modular exponentiation and store powers of 2 in a precomputed array.
 *
 * Time Complexity  : O(n log n), due to sorting. The two-pointer scan is O(n).
 * Space Complexity : O(n), to store the power array.
 */

class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    int numSubseq(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // For each element in the subsequence we have two choices (pick or leave)
        // So if we have 3 elements in the subsequence we have 2*2*2 = 2^3 choices
        // Precompute powers of 2 up to n: power[i] = 2^i % MOD
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            power[i] = (power[i - 1] * 2LL) % MOD;
        }

        int left = 0, right = n - 1;
        int result = 0;

        // Two-pointer approach
        while (left <= right) 
        {
            if (nums[left] + nums[right] <= target) 
            {
                // All subsets from left to right are valid
                result = (result + power[right - left]) % MOD;
                ++left;
            } 
            else 
            {
                // Try a smaller max element
                --right;
            }
        }

        return result;
    }
};