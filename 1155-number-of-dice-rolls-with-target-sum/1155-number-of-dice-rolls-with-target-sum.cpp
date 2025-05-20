class Solution {
private:
    static const int MAX_DICES = 31;       // Max value for n = 30
    static const int MAX_TARGET = 1001;    // Max value for target = 1000
    const int MOD = 1e9 + 7;
    int memory[MAX_DICES][MAX_TARGET];
    int faces;

public:
    /*
     * Approach:
     * - Use top-down dynamic programming (memoization) to compute the number of ways
     *   to roll `n` dice with `k` faces to sum up to the target.
     * - For each dice roll, try all face values [1..k], subtract the chosen value from the target,
     *   and recursively calculate the number of ways for the remaining dice and updated target.
     * - Store intermediate results in a DP table to avoid recomputation.
     * 
     * Time Complexity: O(N * M * K)
     * - N = number of dice
     * - M = target sum
     * - K = number of faces
     * - Each state (dice count and target) is computed once, and for each, we iterate up to K faces.
     * 
     * Space Complexity: O(N * M)
     * - Due to the memoization table storing intermediate results for [dices][amount].
     */
    int numRollsToTarget(int n, int k, int target) 
    {
        faces = k;
        memset(memory, -1, sizeof(memory));
        return numRolls(n, target);
    }

    int numRolls(int dices, int amount)
    {
        // Base case: all dice used and exact target achieved
        if (dices == 0 && amount == 0)
            return 1;

        // Base case: invalid state
        if (dices == 0 || amount <= 0)
            return 0;

        int &ret = memory[dices][amount];
        if (ret != -1)
            return ret;

        ret = 0;
        // Try all face values [1..faces] for the current dice
        for (int i = 1; i <= faces; i++)
        {
            ret = (ret + numRolls(dices - 1, amount - i)) % MOD;
        }

        return ret;
    }
};