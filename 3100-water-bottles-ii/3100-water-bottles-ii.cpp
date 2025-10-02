class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) 
    {
        int emptyBottles = numBottles, drunkBottles = numBottles;

        while(emptyBottles >= numExchange)
        {
            emptyBottles -= numExchange - 1;
            ++drunkBottles;
            ++numExchange;
        }

        return drunkBottles;
    }
};