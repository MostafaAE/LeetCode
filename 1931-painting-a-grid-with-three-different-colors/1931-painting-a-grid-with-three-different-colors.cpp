class Solution {
private:
    static const int MAX = 1024, MOD = 1e9 + 7;
    int memory[MAX][MAX];  // Memoization table
    int m, n;              // Grid dimensions

public:
    /*
     * Approach:
     * - Use memoized DFS (Top-down DP) with bitmasking to represent column colors.
     * - We iterate column by column, row by row.
     * - At each cell, try coloring with 1, 2, or 3 (R, G, B) ensuring:
     *     * No two adjacent cells in the same column share the same color.
     *     * No two adjacent cells in the same row (across columns) share the same color.
     * - Use 2 bits per row cell in the bitmask to encode color state.
     * - Cache results for each column based on the previous column's mask.
     */
    int colorTheGrid(int _m, int _n) 
    {
        m = _m;
        n = _n;
        memset(memory, -1, sizeof(memory));

        // Start from column 0, empty previous mask, and row 0
        return dp(0, 0, 0, 0);
    }

    // Recursive DP to color grid column by column
    int dp(int c, int prevColMask, int r, int curColMask) 
    {
        if (c == n)
            return 1;  // Completed coloring all columns

        int& ret = memory[c][prevColMask];
        if (ret != -1)
            return ret;

        // Move to next column once current column is fully colored
        if (r == m)
            return dp(c + 1, curColMask, 0, 0);

        int ans = 0;
        for (int i = 1; i <= 3; ++i)  // Try colors [1, 2, 3]
        {
            // Ensure different color from above and from left neighbor
            if (getColor(prevColMask, r) != i && (r == 0 || getColor(curColMask, r - 1) != i))
            {
                int updatedMask = setColor(curColMask, r, i);
                ans = (ans + dp(c, prevColMask, r + 1, updatedMask)) % MOD;
            }
        }

        if (r == 0)
            ret = ans;

        return ans;
    }

    // Retrieve color at position `pos` from bitmask (2 bits per position)
    int getColor(int mask, int pos)
    {
        return (mask >> (2 * pos)) & 3;
    }

    // Set `color` at position `pos` in bitmask (2 bits per position)
    int setColor(int mask, int pos, int color) 
    {
        return mask | (color << (2 * pos));
    }
};