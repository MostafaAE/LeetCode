const int MAX = 5000 + 1;
int memory[MAX][2];
vector<int> pricesg;
class Solution {
public:
    /* 
    * Approach:
    * Dynamic Programming Memoization (Pick or Leave approach)
    * 
    * Complexity:
    * Time Complexity : O(N)
    * Space Complexity : O(N)
    */
    int maxProfit(vector<int>& prices) 
    {
        pricesg = prices;
        memset(memory, -1, sizeof(memory));
        return profit(0, 0);
    }
    
    int profit(int idx, int haveStock)
    {
        if(idx >= (int)pricesg.size())
            return 0;
        
        int &ret = memory[idx][haveStock];
        if(ret != -1)
            return ret;
        
        int choice1{};
        
        // sell the last stock
        if(haveStock)
            choice1 = pricesg[idx] + profit(idx + 2, 0);
        // buy the stock
        else
            choice1 = -pricesg[idx] + profit(idx + 1, 1);
        
        // leave the stock
        int choice2 = profit(idx + 1, haveStock);
        
        return ret = max(choice1, choice2);
    }
};