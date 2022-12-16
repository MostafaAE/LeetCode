class Solution {
    const static int MAX = 1000 + 1;
    int memory[MAX];
    vector<int> cost;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     *
     * Complexity:
     * Time Complexity : O(N)
     * Space Complexity : O(N)
     */
    int minCostClimbingStairs(vector<int>& _cost) 
    {
        cost = _cost;
        memset(memory, -1, sizeof(memory));
        return min(minCost(0), minCost(1));
    }
    
    int minCost(int idx)
    {
        if(idx >= (int)cost.size())
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        int jump1 = minCost(idx+1);
        int jump2 = minCost(idx+2);
        
        return ret = cost[idx] + min(jump1, jump2);
    }
};