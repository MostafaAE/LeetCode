class Solution {
private:
    static const int MAX = 100000 + 1;
    long long memory[MAX];
    vector<vector<int>> qs;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (knapsack variant => pick or leave pattern)
     * 
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    long long mostPoints(vector<vector<int>>& questions) 
    {
        qs = questions;
        memset(memory, -1, sizeof(memory));
        
        return maxPoints(0);
    }
    
    long long maxPoints(int idx)
    {
        if(idx >= (int)qs.size())
            return 0;
        
        long long &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        long long solve = qs[idx][0] + maxPoints(idx + qs[idx][1] + 1);
        long long skip = maxPoints(idx + 1);
        
        return ret = max(solve, skip);
    }
};