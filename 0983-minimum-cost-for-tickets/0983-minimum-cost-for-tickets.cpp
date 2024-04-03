class Solution {
private:
    static const int MAX = 365 + 1;
    int memory[MAX];
    vector<int> days, costs, passes{1, 7, 30};
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (pick next mask one approach).
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int mincostTickets(vector<int>& _days, vector<int>& _costs) 
    {
        memset(memory, -1, sizeof(memory));
        costs = _costs;
        days = _days;
        
        return minCost(0);
    }
    
    int minCost(int idx)
    {
        if(idx >= (int)days.size())
            return 0;
        
        int& ret = memory[idx];
        if(ret != -1)
            return ret;
        
        ret = INT_MAX;
        for(int i = 0 ; i < costs.size() ; i++)
        {
            int validTo = days[idx] + passes[i];
            int cost = costs[i];
            for(int j = idx + 1 ; j < days.size() ; j++)
            {
                if(days[j] >= validTo)
                {
                    cost += minCost(j);
                    break;
                }
            }
            
            ret = min(ret, cost);
        }
        
        return ret;
    }
};