class Solution {
private:
    static const int MAXIDX = 300 + 1, MAXAMOUNT = 5000 + 1;
    int memory[MAXIDX][MAXAMOUNT];
    vector<int> coins;
        
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Counting DP
     *
     * Complexity:
     * Time Complexity : O(MN)
     * Space Complexity : O(MN)
     */
    int change(int amount, vector<int>& _coins) 
    {
        memset(memory, -1 , sizeof(memory));
        coins = _coins;
        return coinChange(0, amount);
    }
    
    int coinChange(int idx, int remaining)
    {
        if(remaining < 0)
            return 0;
        
        if(remaining == 0)
            return 1;
        
        if(idx == (int)coins.size())
            return 0;
        
        int &ret = memory[idx][remaining];
        if(ret != -1)
            return ret;
        
        int leave = coinChange(idx+1, remaining);
        int pick = coinChange(idx, remaining-coins[idx]);
        
        return ret = pick + leave;
    }
    
};