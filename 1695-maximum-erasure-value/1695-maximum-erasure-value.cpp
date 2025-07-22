/*
 * Approach:
 * We use a sliding window technique with two pointers (left and right) to maintain a window 
 * that contains only unique elements. 
 * 
 * - We maintain a running sum `curSum` of the current window.
 * - If we encounter a duplicate, we shrink the window from the left until the duplicate is removed.
 * - At each step, we update the maxSum with the current window sum.
 *
 * Time Complexity  : O(n), where n is the length of nums. Each element is added and removed from the set at most once.
 * Space Complexity : O(n), for the unordered_set that stores elements in the current window.
 */

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int left = 0, right = 0;
        int curSum = 0, maxSum = 0;
        unordered_set<int> seen;

        while (right < nums.size()) 
        {
            // If nums[right] is already in the set, move left to remove duplicates
            while (seen.count(nums[right])) 
            {
                seen.erase(nums[left]);
                curSum -= nums[left++];
            }

            // Add current number to the set and update the current sum
            seen.insert(nums[right]);
            curSum += nums[right++];

            // Update the maximum sum found so far
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};