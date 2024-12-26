class Solution {
private:
    int totalSum{}; // To store the total sum of the array elements
public:
    /**
     * Approach:
     * - This solution uses Dynamic Programming with Memoization to calculate the number of ways
     *   to achieve the target sum by assigning + or - signs to elements.
     * - A memory table (`memory`) is used to store intermediate results to avoid redundant calculations.
     * - The range of possible sums is from -totalSum to +totalSum. To handle this, we use an offset
     *   (totalSum) to shift all sums into non-negative indices.
     * 
     * Complexity:
     * Time Complexity: O(n * t), where n is the size of the array and t = 2 * totalSum + 1 is the range of possible sums.
     * Space Complexity: O(n * t) for the memoization table.
     */
    int findTargetSumWays(vector<int>& nums, int target) {
        // Calculate the total sum of the array
        totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Initialize a memoization table with size [nums.size()][2 * totalSum + 1]
        vector<vector<int>> memory(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));

        // Start the recursive function to count the number of ways
        return countSum(nums, 0, 0, target, memory);
    }

    int countSum(vector<int>& nums, int idx, int curSum, int target, vector<vector<int>>& memory) {
        // Base case: If we reach the end of the array
        if (idx >= nums.size())
            return curSum == target; // Return 1 if curSum matches the target, otherwise 0

        // Check if the current state is already computed in the memoization table
        if (memory[idx][curSum + totalSum] != INT_MIN)
            return memory[idx][curSum + totalSum];

        // Recursive call: Add the current number
        int add = countSum(nums, idx + 1, curSum + nums[idx], target, memory);

        // Recursive call: Subtract the current number
        int subtract = countSum(nums, idx + 1, curSum - nums[idx], target, memory);

        // Store the result in the memoization table and return the total count
        return memory[idx][curSum + totalSum] = add + subtract;
    }
};
