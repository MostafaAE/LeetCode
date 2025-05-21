class Solution {
private:
    static const int MAX = 50 + 1;
    const int MOD = 1e9 + 7;
    int memory[MAX][MAX][MAX];  // DP memo table: memory[row][col][remainingMoves]
    int m, n;

    // Directions: up, down, left, right
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1, 1};

public:
    /*
     * Approach:
     * Dynamic Programming with Memoization (Top-down)
     * 
     * We try to move from the starting cell in 4 directions recursively.
     * If the move goes out of boundary, we count it as a valid path.
     * If the remainingMoves reach 0 before going out, we stop.
     * We use memoization to cache results for each (row, col, remainingMoves) state.
     *
     * Time Complexity : O(M * N * K) 
     *      where M = rows, N = cols, K = maxMove
     * Space Complexity : O(M * N * K)
     */
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        this->m = m;
        this->n = n;

        // Initialize memoization table to -1
        memset(memory, -1, sizeof(memory));

        // Start recursive DP from the starting cell
        return numPaths(startRow, startColumn, maxMove);
    }

    // Recursive function to count paths from (row, col) with remaining moves
    int numPaths(int row, int col, int remainingMoves)
    {
        // If the current cell is out of boundary, it's a valid path
        if(row < 0 || row >= m || col < 0 || col >= n)
            return 1;

        // If no more moves allowed and still inside grid, it's invalid
        if(remainingMoves == 0)
            return 0;

        // Check if result is already computed
        int &ret = memory[row][col][remainingMoves];
        if(ret != -1)
            return ret;

        ret = 0;
        // Try all four directions
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = row + dr[d];
            int nc = col + dc[d];

            // Add the number of paths from the neighboring cell
            ret = (ret + numPaths(nr, nc, remainingMoves - 1)) % MOD;
        }

        return ret;
    }
};