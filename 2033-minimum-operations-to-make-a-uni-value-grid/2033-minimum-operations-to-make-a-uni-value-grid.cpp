class Solution {
public:
    /**
     * Approach:
     * - The goal is to make all elements in the grid equal using operations of adding/subtracting `x`.
     * - First, extract all elements into a 1D array.
     * - Second, find the **median** of the elements.
     * - The median minimizes the total absolute difference, making it the optimal target value.
     * - Compute the total number of operations required.
     *
     * Complexity Analysis:
     * - **Overall Time Complexity**: **O(N log N)**, where N = rows x cols
     * - **Space Complexity**: **O(N)** (storing elements in a vector).
     */
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        vector<int> vals;
        int rows = grid.size(), cols = grid[0].size();

        // Step 1: Flatten the 2D grid into a 1D array
        for (int row = 0; row < rows; ++row) 
        {
            for (int col = 0; col < cols; ++col) 
            {
                vals.push_back(grid[row][col]);
            }
        }

        int length = vals.size();

        // Step 2: Find the median using nth_element
        nth_element(vals.begin(), vals.begin() + length / 2, vals.end());
        int target = vals[length / 2];

        // Step 3: Calculate minimum operations required
        int result = 0;
        for (int number : vals) 
        {
            // If any element has a different remainder modulo x, return -1
            if (number % x != target % x) 
                return -1;

            // Compute operations needed to transform `number` into `target`
            result += abs(target - number) / x;
        }

        return result;
    }
};
