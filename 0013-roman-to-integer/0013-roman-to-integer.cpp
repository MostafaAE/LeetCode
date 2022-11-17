class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int romanToInt(string s) 
    {
        int lastVal{1000};
        int sum{};
        unordered_map<char, int> romToInt{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}
                                          , {'C', 100}, {'D', 500}, {'M', 1000}};
    
        for(int i = 0 ; i < (int)s.size() ; i++)
        {
            int curRomVal = romToInt[s[i]];
            
            sum += curRomVal;
            
            if(curRomVal > lastVal)
                sum -= 2*lastVal;
            
            lastVal = romToInt[s[i]];
        }
        
        return sum;
    }
};