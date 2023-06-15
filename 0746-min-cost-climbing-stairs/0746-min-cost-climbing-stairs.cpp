const int MAX = 1000 + 1;
int memory[MAX];
vector<int> costg;
class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     *
     * Complexity:
     * Time Complexity : O(N)
     * Space Complexity : O(N)
     */
    int minCostClimbingStairs(vector<int>& cost) 
    {
        memset(memory, -1, sizeof(memory));
        costg = cost;
        return min(minCost(0), minCost(1));
    }
    
    int minCost(int idx)
    {
        if(idx >= (int)costg.size())
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        int oneStep = minCost(idx + 1);
        int twoSteps = minCost(idx + 2);
        
        return ret = costg[idx] + min(oneStep, twoSteps);
    }
    
};