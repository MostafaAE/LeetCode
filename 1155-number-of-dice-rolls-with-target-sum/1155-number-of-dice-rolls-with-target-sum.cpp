const int MAX_DICES = 30 + 1, MAX_TARGET = 1000 + 1, MOD = 1e9+7;
int memory[MAX_DICES][MAX_TARGET];
int faces;
class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Counting DP
     *
     * Complexity:
     * Time Complexity : O(NMK) 
     * Space Complexity : O(NM) where N is the max dice count, M is the max target, k is the max dice faces
     */
    int numRollsToTarget(int n, int k, int target) 
    {
        faces = k;
        memset(memory, -1, sizeof(memory));
        return numRolls(n, target);
    }
    
    int numRolls(int dices, int amount)
    {
        // all dices sum to the target
        if(dices == 0 && amount == 0)
            return 1;
        
        if(dices == 0 || amount <= 0)
            return 0;
        
        int &ret = memory[dices][amount];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int i = 1 ; i <= faces ; i++)
            ret = (ret + numRolls(dices - 1, amount - i)) % MOD;
        
        return ret;
    }
};