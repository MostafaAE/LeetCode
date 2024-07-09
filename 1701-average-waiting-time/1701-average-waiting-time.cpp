class Solution {
public:
    /**
     * Approach:
     * - Initialize `nextIdleTime` to 0 and `totalWait` to 0.
     * - For each customer, calculate the time at which the server will serve them.
     * - Update `nextIdleTime` to the maximum of the customer's arrival time and the current `nextIdleTime` plus the customer's order time.
     * - Accumulate the waiting time for each customer, which is the difference between `nextIdleTime` and the customer's arrival time.
     * - Finally, return the average waiting time by dividing `totalWait` by the number of customers.
     * 
     * Complexity:
     * - Time Complexity: O(n)
     * - Space Complexity: O(1)
     */
    double averageWaitingTime(vector<vector<int>>& customers) 
    {
        int nextIdleTime = 0;
        long long totalWait = 0;
        
        for(int i = 0 ; i < customers.size() ; ++i)
        {
            nextIdleTime = max(customers[i][0], nextIdleTime) + customers[i][1];
            
            totalWait += nextIdleTime - customers[i][0];
        }
        
        return (double)totalWait / customers.size();
    }
};