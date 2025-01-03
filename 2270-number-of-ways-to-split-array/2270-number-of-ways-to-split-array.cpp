class Solution {
public:
    /**
     * Approach:
     * - Use two variables, `leftSum` and `rightSum`, to calculate the sums dynamically while iterating through the array.
     * - Initialize `rightSum` with the total sum of the array using `accumulate`.
     * - Iterate through the array, updating:
     *     - `leftSum` by adding the current element.
     *     - `rightSum` by subtracting the current element.
     * - If `leftSum` is greater than or equal to `rightSum` at any split point, increment the result.
     *
     * Complexity:
     * Time Complexity: O(n)
     * - Calculating the total sum with `accumulate` takes O(n).
     * - Iterating through the array to count valid splits takes O(n).
     * Space Complexity: O(1)
     */
    int waysToSplitArray(vector<int>& nums) 
    {
        int n = nums.size(), result = 0;

        long long leftSum = 0;
        long long rightSum = accumulate(nums.begin(), nums.end(), 0LL);

        // Iterate through the array to find valid splits
        for (int i = 0; i < n - 1; ++i) 
        {
            leftSum += nums[i];
            rightSum -= nums[i];

            if (leftSum >= rightSum)
                ++result;
        }

        return result;
    }
};
