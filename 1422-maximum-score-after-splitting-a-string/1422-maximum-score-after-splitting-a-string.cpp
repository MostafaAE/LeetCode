class Solution {
public:
    int maxScore(string s) 
    {
        int n = s.size(), result{}, zerosCount{}, onesCount{};

        for(char c : s)
            onesCount += (c == '1');
        
        for(int i = 0 ; i < n-1 ; ++i)
        {
            if(s[i] == '1')
                --onesCount;
            else
                ++zerosCount;
            
            result = max(result, zerosCount + onesCount);
        }

        return result;
    }
};