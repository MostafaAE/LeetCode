class Solution {
public:
    /*
     * Approach:
     * - Use a single pass to track the minimum price seen so far (`curMin`).
     * - At each step, calculate potential profit by selling at current price.
     * - Update `maxProfit` if the current profit is higher than previous max.
     *
     * Complexity:
     * Time Complexity  : O(n) — where n is the size of the prices array.
     * Space Complexity : O(1) — constant extra space used.
     */
    int maxProfit(vector<int>& prices) 
    {
        int maxProfit = 0;
        int curMin = prices[0];

        for (int i = 1; i < (int)prices.size(); ++i)
        {
            // Try selling at current price and update max profit
            maxProfit = max(maxProfit, prices[i] - curMin);
            
            // Update minimum price seen so far
            curMin = min(curMin, prices[i]);
        }

        return maxProfit;
    }
};