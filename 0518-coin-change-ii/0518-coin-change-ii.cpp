const int MAX_IDX = 300 + 1, MAX_AMOUNT = 5000 + 1;
int memory[MAX_IDX][MAX_AMOUNT];
vector<int> coinsg;

class Solution {      
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Counting DP
     *
     * Complexity:
     * Time Complexity : O(MN)
     * Space Complexity : O(MN) where M is the max target, and N is the max index
     */
    int change(int amount, vector<int>& coins) 
    {
        memset(memory, -1 , sizeof(memory));
        coinsg = coins;
        return coinChange(0, amount);
    }
    
    int coinChange(int idx, int amount)
    {
        if(amount == 0)
            return 1;
        
        if(idx >= (int)coinsg.size() || amount < 0)
            return 0;
        
        int &ret = memory[idx][amount];
        if(ret != -1)
            return ret;
        
        int pick = coinChange(idx, amount - coinsg[idx]);
        int leave = coinChange(idx + 1, amount);

        return ret = pick + leave;
    }
   
};