class Solution {
public:
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