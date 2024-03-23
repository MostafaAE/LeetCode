class Solution {
private:
    static const int MAX_COINS = 12 + 1, MAX_AMOUNT = 10000 + 1;
    int memory[MAX_COINS][MAX_AMOUNT];
    vector<int> coinsg;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (knapsack variant => pick or leave pattern)
     * 
     *
     * Complexity:
     * Time Complexity : O(MN)
     * Space Complexity : O(MN) where M is the max amount, and N is the max coins length
     */
    int coinChange(vector<int>& coins, int amount) 
    {
        coinsg = coins;
        memset(memory, -1, sizeof(memory));
        
        int minNumCoins = minCoins(0, amount);

        return minNumCoins >= MAX_AMOUNT ? -1 : minNumCoins;
    }
    
    int minCoins(int idx, int amount)
    {
        if(idx >= coinsg.size())
            return MAX_AMOUNT;
        
        if(amount == 0)
            return 0;
        
        int& ret = memory[idx][amount];
        if(ret != -1)
            return ret;
        
        int pick{INT_MAX};
        if(coinsg[idx] <= amount)
            pick = 1 + minCoins(idx, amount - coinsg[idx]);
        
        int leave = minCoins(idx + 1, amount);
        
        return ret = min(pick, leave);
    }
};