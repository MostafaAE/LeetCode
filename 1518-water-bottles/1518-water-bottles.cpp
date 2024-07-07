class Solution {
public:
    /**
     * Approach:
     * - Start with the initial number of full water bottles.
     * - While there are enough empty bottles to exchange for a new full bottle:
     *   - Calculate how many new full bottles can be obtained from the empty bottles.
     *   - Update the number of empty bottles to reflect the new full bottles and the remainder.
     *   - Add the number of new full bottles to the total count of water bottles consumed.
     *
     * Complexity:
     * - Time Complexity: O(logM(N)), where M is `numExchange`, N is `numBottles`.
     * - Space Complexity: O(1)
     */
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int totalWaterBottles = numBottles;
        
        while(numBottles >= numExchange)
        {
            int exchangedBottles = numBottles / numExchange;
            
            numBottles = numBottles % numExchange + exchangedBottles;
            
            totalWaterBottles += exchangedBottles;
        }
        
        return totalWaterBottles;
    }
};