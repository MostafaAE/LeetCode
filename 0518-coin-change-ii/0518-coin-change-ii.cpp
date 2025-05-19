class Solution {
private:
    static const int MAX_IDX = 301, MAX_AMOUNT = 5001;
    int memory[MAX_IDX][MAX_AMOUNT];
    vector<int> coins;
public:
    /*
     * Approach:
     * - Use top-down dynamic programming with memoization.
     * - At each step, decide whether to:
     *     * Pick the current coin (stay at same index, reduce amount).
     *     * Skip the current coin (move to next index).
     * - Count all combinations (not permutations) to reach the target amount.
     *
     * Time Complexity: O(N * M), where N = number of coins, M = target amount.
     * Space Complexity: O(N * M) for the memoization table.
     */
    int change(int amount, vector<int>& coins) 
    {
        memset(memory, -1 , sizeof(memory));
        this->coins = coins;
        return coinChange(0, amount);
    }
    
    // Recursive function to count combinations from index `idx` to reach `amount`
    int coinChange(int idx, int amount)
    {
        if (amount == 0)
            return 1;  // Found a valid combination

        if (idx >= (int)coins.size() || amount < 0)
            return 0;  // Out of coins or amount went negative

        int &ret = memory[idx][amount];
        if (ret != -1)
            return ret;

        // Option 1: Take current coin (don't increment index)
        int pick = coinChange(idx, amount - coins[idx]);

        // Option 2: Skip current coin
        int leave = coinChange(idx + 1, amount);

        return ret = pick + leave;
    }
};