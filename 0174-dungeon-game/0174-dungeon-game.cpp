class Solution {
private:
    static const int MAX = 200 + 1;
    int memory[MAX][MAX];

public:
    /*
     * Approach:
     * Dynamic Programming (Memoization)
     * 
     * Problem: Find the minimum initial health required to survive a dungeon grid from top-left to bottom-right.
     * Each cell adds or subtracts from the knight's health. The knight must always have health ≥ 1.
     * 
     * We define `minHP(r, c)` as the minimum *health debt* needed starting from cell (r, c) to the goal.
     * - If at the bottom-right cell, we return its value directly.
     * - For other cells, we recursively take the max of the path to the right or downward,
     *   and add the current cell's value.
     * - If this sum is negative, it means we need extra health to survive → track the *minimum* health (<= 0).
     * - We take `abs(min(..., 0)) + 1` at the end to ensure health never drops below 1.
     *
     * Time Complexity: O(M * N)
     * - Each cell is visited once and memoized.
     * 
     * Space Complexity: O(M * N)
     * - Due to memoization table.
     */
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        // Initialize memoization table
        memset(memory, -1, sizeof(memory));
        
        // We add 1 to ensure health never drops below 1
        // Take abs(min(..., 0)) to convert health debt to positive requirement
        return 1 + abs(min(minHP(0, 0, dungeon), 0));
    }

    int minHP(int r, int c, vector<vector<int>>& grid)
    {
        // Base case: out of bounds → invalid path
        if(r >= grid.size() || c >= grid[0].size())
            return INT_MIN;

        // Base case: at the goal cell (bottom-right)
        if(r == grid.size() - 1 && c == grid[0].size() - 1)
            return grid[r][c];

        // Return memoized result
        int &ret = memory[r][c];
        if(ret != -1)
            return ret;

        // Explore both directions (right and down)
        int rightward = minHP(r, c + 1, grid);
        int downward = minHP(r + 1, c, grid);

        // Take the better path (max of both, since we're minimizing *health debt*)
        int bestNext = max(rightward, downward);

        // Add current cell's value to the best next step
        // Cap the result at 0 because positive health is not debt
        return ret = grid[r][c] + min(bestNext, 0);
    }
};
