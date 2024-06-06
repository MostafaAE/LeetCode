class Solution {
public:
    /*
    * Approach:
    * - Check if the hand size is divisible by groupSize.
    * - Use a map to count the frequency of each card.
    * - Iterate through the map, forming groups of groupSize.
    * - For each card in the group, ensure that there are enough consecutive cards to form a valid group.
    * - Update the map accordingly, removing entries with zero counts.
    *
    * Complexity:
    * - Time Complexity: O(n log n), where n is the number of cards in the hand.
    * - Space Complexity: O(n)
    */
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        // check if the hand size is divisible by groupSize
        if(hand.size() % groupSize != 0)
            return false;
        
        map<int, int> valToCount;
        for(int i = 0 ; i < hand.size() ; ++i)
            valToCount[hand[i]]++;
        
        while(!valToCount.empty())
        {
            int curVal = valToCount.begin()->first;
            
            for(int i = 0 ; i < groupSize ; ++i)
            {
                if(valToCount[curVal] == 0)
                    return false;
                
                valToCount[curVal]--;
                
                if(valToCount[curVal] < 1)
                    valToCount.erase(curVal);
                
                curVal++;
            }
        }
        
        return true;
    }
};