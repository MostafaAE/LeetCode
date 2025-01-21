class Solution {
public:
    /**
     * Approach:
     * - Use prefix sums to efficiently calculate the sum of elements in both rows up to a certain point.
     * - Iterate over possible split points in the grid and compute the total score for each split.
     * - For each split, calculate the remaining elements in the top and bottom rows and determine the second robot’s score.
     * - The goal is to minimize the second robot's score by choosing the best split point.
     * 
     * Complexity:
     * - Time: O(n), where n is the number of columns in the grid.
     *   - O(n) to compute the prefix sums for both rows.
     *   - O(n) to iterate over the possible split points and calculate the scores.
     * - Space: O(n), for the prefix sum arrays.
     */
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size()
        ;
        vector<long long> topPrefix(n + 1, 0), bottomPrefix(n + 1, 0);

        // Compute prefix sums for both rows
        for (int i = 0; i < n; ++i) 
        {
            topPrefix[i + 1] = topPrefix[i] + grid[0][i];
            bottomPrefix[i + 1] = bottomPrefix[i] + grid[1][i];
        }

        long long result = LLONG_MAX;

        // Simulate the split point
        for (int i = 0; i < n; ++i) 
        {
            long long topRemaining = topPrefix[n] - topPrefix[i + 1];
            long long bottomRemaining = bottomPrefix[i];

            // Second robot's score is the maximum of remaining in either row
            long long secondRobotScore = max(topRemaining, bottomRemaining);

            // Minimize the second robot's maximum score
            result = min(result, secondRobotScore);
        }

        return result;
    }
};
