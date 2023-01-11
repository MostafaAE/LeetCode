class Solution {
private:
    static const int MAX_TARGET = 1000 + 1, MAX_DICE = 30+1;
    int memory[MAX_DICE][MAX_TARGET];
    int n, k;
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
    int numRollsToTarget(int _n, int _k, int target) 
    {
        n = _n;
        k = _k;
        memset(memory, -1, sizeof(memory));
        
        return numRolls(0, target);
    }
    
    int numRolls(int dice, int target)
    {
        if(target < 0)
            return 0;
        
        // all dices sum to the target
        if(dice == n && target == 0)
            return 1;
        
        if(dice == n || target == 0)
            return 0;
        
        int &ret = memory[dice][target];
        if(ret != -1)
            return ret;
        
        
        ret = 0;
        for(int i = 1 ; i <= k ; i++)
            ret = (ret + numRolls(dice + 1, target - i)) % (int)(1e9+7);
        
        return ret;
    }
};