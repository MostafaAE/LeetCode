/**
 * Approach:
 * - This problem is about finding the number of ways to tile a 2 x n board using:
 *   1. Dominoes (1 x 2 tiles) both vertically and horizontally.
 *   2. Trominoes (L-shaped tiles that cover three squares).
 * 
 * - This is a dynamic programming problem with a known recurrence:
 *   dp[n] = 2 * dp[n - 1] + dp[n - 3]
 *   Explanation:
 *   - 2 * dp[n-1]: one for placing a vertical domino at the end, another for placing an L-shaped tromino in two orientations.
 *   - dp[n-3]: represents complex cases where a tromino covers parts of three previous columns.
 * 
 * - Base cases:
 *   dp[1] = 1 (one vertical domino)
 *   dp[2] = 2 (two vertical or two horizontal)
 *   dp[3] = 5 (manually counted possibilities)
 * 
 * Time Complexity: O(n)
 * - We compute dp[i] from i = 4 to n in a loop.
 * 
 * Space Complexity: O(n)
 * - We use a DP array of size `n + 1`.
 */

class Solution {
public:
    int numTilings(int n) 
    {
        const int MOD = 1e9 + 7;
        
        vector<long long> memory(1001, 0);

        // Base cases
        memory[1] = 1;  // Only one vertical domino
        memory[2] = 2;  // Two vertical or two horizontal dominoes
        memory[3] = 5;  // Calculated manually: 5 possible tilings

        for (int i = 4; i <= n; ++i)
        {
            memory[i] = 2 * memory[i - 1] + memory[i - 3];
            memory[i] %= MOD;
        }

        return memory[n];
    }
};
