/*
 * Approach:
 * - We want to find the sum of all **unique positive integers** in the array.
 * - If all numbers are non-positive, return the **maximum number** (which is the least negative).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
        int sum = 0;
        int maxElement = INT_MIN;
        unordered_set<int> seen;

        for (int num : nums)
        {
            // Add only unique positive numbers
            if (num > 0 && !seen.count(num))
            {
                sum += num;
                seen.insert(num);
            }

            // Track the maximum number for edge case where all are non-positive
            maxElement = max(maxElement, num);
        }

        // If all elements are <= 0, return the largest (least negative) number
        if (maxElement <= 0)
            return maxElement;

        return sum;
    }
};