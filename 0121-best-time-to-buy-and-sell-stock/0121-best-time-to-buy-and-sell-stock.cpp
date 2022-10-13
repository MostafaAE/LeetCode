class Solution {
public:
    
    // Time Complexity = O(n)
    // Space Complexity = O(1)
    int maxProfit(vector<int>& prices) 
    {
        int maxProfit{}, curMin = prices[0];
        
        for(int i = 1 ; i < (int)prices.size() ; i++)
        {
            if(prices[i]-curMin > maxProfit)
                maxProfit = prices[i]-curMin;
            
            if(prices[i] < curMin)
                curMin = prices[i];
        }
        
        return maxProfit;
        
    }
};