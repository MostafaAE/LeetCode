class Solution {
public:
    /**
     * Approach:
     * - Start by calculating the initial sum of the top row (topPrefix) and initialize bottomPrefix to 0.
     * - Iterate over the grid and simulate the split by updating the topPrefix (subtracting the current element from it)
     *   and bottomPrefix (adding the current element to it).
     * - For each split, calculate the second robot's score as the maximum of the remaining values in either row.
     * - Minimize the second robot’s maximum score as we progress through the grid.
     * 
     * Complexity:
     * - Time: O(n), where n is the number of columns in the grid.
     *   - O(n) for calculating the initial sum of the top row and updating the prefixes as we iterate over the columns.
     * - Space: O(1), as we only use a constant amount of extra space for the two prefix variables.
     */
    long long gridGame(vector<vector<int>>& grid) 
    {
        int n = grid[0].size();

        // Initial prefix sum for the top row
        long long topPrefix = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottomPrefix = 0;

        long long result = LLONG_MAX;

        // Simulate the split point
        for (int i = 0; i < n; ++i) 
        {
            topPrefix -= grid[0][i];

            // Second robot's score is the maximum of remaining in either row
            long long secondRobotScore = max(topPrefix, bottomPrefix);

            // Minimize the second robot's maximum score
            result = min(result, secondRobotScore);

            bottomPrefix += grid[1][i];
        }

        return result;
    }
};
