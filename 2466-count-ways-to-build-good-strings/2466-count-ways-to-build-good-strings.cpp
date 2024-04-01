class Solution {
private:
    static const int MAX = 100000 + 1, MOD = 1e9 + 7;
    int memory[MAX];
    int low, high, zero, one;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Counting DP
     *
     * Complexity:
     * Time Complexity : O(N)
     * Space Complexity : O(N)
     */
    int countGoodStrings(int _low, int _high, int _zero, int _one) 
    {
        memset(memory, -1, sizeof(memory));
        low = _low;
        high = _high;
        zero = _zero;
        one = _one;
        
        return countStrs(0);
    }
    
    int countStrs(int len)
    {
        if(len > high)
            return 0;
        
        int &ret = memory[len];
        if(ret != -1)
            return ret;
        
        ret = 0;
        if(len >= low && len <= high)
            ret++;
        
        ret += countStrs(len + zero);
        ret += countStrs(len + one);
        return ret = ret%MOD;
    }
};