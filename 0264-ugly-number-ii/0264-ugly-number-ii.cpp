class Solution {
private:
    int factors[3]{2, 3, 5};
public:
    /**
     * Approach:
     * - Use a min-heap (priority queue) to keep track of the smallest ugly numbers.
     * - Start by pushing `1` into the heap as the first ugly number.
     * - Use a set to ensure only unique ugly numbers are processed.
     * - Extract the smallest element from the heap and generate new ugly numbers by multiplying it by 2, 3, and 5.
     * - Continue this process until we have generated `n` unique ugly numbers.
     *
     * Complexity:
     * - Time Complexity: O(n log n), where `n` is the input number. Each insertion and extraction in the heap is O(log n).
     * - Space Complexity: O(n), due to the heap and set storing up to `n` elements.
     */
    int nthUglyNumber(int n) 
    {
        int result{};
        priority_queue<long, vector<long>, greater<long>> uglyNums;
        unordered_set<long> uniqueNums;
        
        uglyNums.push(1);
        
        while(uniqueNums.size() < n)
        {
            long ugly = uglyNums.top();
            uglyNums.pop();
            
            if(!uniqueNums.insert(ugly).second)
                continue;
        
            result = ugly;
            
            for(int j = 0 ; j < 3 ; ++j)
                uglyNums.push(ugly * factors[j]);
        }
        
        return result;
    }
};