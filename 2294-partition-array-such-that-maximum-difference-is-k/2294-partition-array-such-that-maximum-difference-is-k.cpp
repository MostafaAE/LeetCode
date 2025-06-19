class Solution {
public:
    /*
    * Approach:
    * - Sort the nums array in increasing order.
    * - Traverse the array from left to right.
    * - Keep track of the current minimum of the current subarray (group).
    * - If the current number exceeds currentMinimum + k, start a new group and update currentMinimum.
    *
    * Time Complexity: O(n log n)
    * Space Complexity: O(log n) for sorting.
    */
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int currentMinimum = nums[0];
        int result = 1;

        for (int i = 1; i < n; ++i)
        {
            // If the current number is too far from the current minimum
            if (nums[i] - currentMinimum > k)
            {
                currentMinimum = nums[i]; // Start new group
                ++result;
            }
        }

        return result;
    }
};