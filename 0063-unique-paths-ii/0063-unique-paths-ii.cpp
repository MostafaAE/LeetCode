class Solution {
private:
    static const int MAX = 100 + 1;
    int memory[MAX][MAX];
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Use DP on the grid to count the number of unique paths from top-left to bottom-right,
     * avoiding obstacles (cells with value 1).
     *
     * We define cntPaths(r, c) as the number of unique paths from cell (r, c) to the bottom-right.
     * We use memoization to store and reuse overlapping subproblem results.
     *
     * Complexity:
     * Time Complexity  : O(MN) — where M = rows, N = cols of the grid.
     * Space Complexity : O(MN) — for the memoization table.
     */
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        memset(memory, -1, sizeof(memory));
        return cntPaths(0, 0, grid);
    }

    int cntPaths(int r, int c, vector<vector<int>>& grid)
    {
        // Out of bounds or hitting an obstacle
        if (r >= (int)grid.size() || c >= (int)grid[0].size() || grid[r][c] == 1)
            return 0;

        // Reached destination
        if (r == (int)grid.size() - 1 && c == (int)grid[0].size() - 1)
            return 1;

        int &ret = memory[r][c];
        if (ret != -1)
            return ret;

        // Move right and down
        int moveRight = cntPaths(r, c + 1, grid);
        int moveDown = cntPaths(r + 1, c, grid);

        return ret = moveRight + moveDown;
    }
};