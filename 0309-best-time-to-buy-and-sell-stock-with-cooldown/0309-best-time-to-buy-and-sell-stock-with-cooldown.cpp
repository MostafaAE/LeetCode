class Solution {
private:
    const static int MAX = 5000 + 1;
    int memory[MAX][2];
    vector<int> prices;
    
public:
    /* 
    * Approach:
    * Dynamic Programming Memoization (Pick or Leave approach)
    * 
    * Complexity:
    * Time Complexity : O(N)
    * Space Complexity : O(N)
    */
    int maxProfit(vector<int>& _prices) 
    {
        prices = _prices;
        memset(memory, -1, sizeof(memory));
        return profit(0, 0);
    }
    
    int profit(int idx, int haveStock)
    {
        if(idx >= (int)prices.size())
            return 0;
        
        int &ret = memory[idx][haveStock];
        if(ret != -1)
            return ret;
        
        int sellChoice{}, buyChoice{}, leaveChoice{};
        
        // sell the last bought stock
        if(haveStock)
            sellChoice = prices[idx] + profit(idx + 2, 0);
        
        // buy this stock
        else
            buyChoice = -prices[idx] + profit(idx + 1, 1);
        
        // leave this stock
        leaveChoice = profit(idx + 1, haveStock);
        
        return ret = max(sellChoice, max(buyChoice, leaveChoice));
    }
};