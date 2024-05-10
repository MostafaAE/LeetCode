class StockSpanner {
private:
    stack<pair<int, int>> priceSpan;
public:
    /* 
    * Approach:
    * - Maintain a monotonic decreasing stack to store pairs of (price, span).
    * - For each received price, if the new price is greater than or equal to the price on top of the stack, keep popping elements from the stack and update the current span.
    * - Push the new price and span pair onto the stack, and return the calculated span as the result.
    *
    * Complexity:
    * - Time Complexity: O(n), on average O(1) for each call to next().
    * - Space Complexity: O(n), where n is the number of elements inserted so far.
    */
    StockSpanner() {}
    
    int next(int price) 
    {
        int span = 1;
        while(!priceSpan.empty() && price >= priceSpan.top().first)
        {
            span += priceSpan.top().second;
            priceSpan.pop();
        }
        
        priceSpan.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */