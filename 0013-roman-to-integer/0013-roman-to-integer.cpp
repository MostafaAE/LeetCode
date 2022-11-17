class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int romanToInt(string s) 
    {
        int n = (int)s.size();
        int sum{};
        unordered_map<char, int> romToInt{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}
                                          , {'C', 100}, {'D', 500}, {'M', 1000}};
    
        for(int i = 0 ; i < n ; i++)
        {
            int curRomVal = romToInt[s[i]];
            
            if(i < n-1 && romToInt[s[i+1]] > curRomVal)
                sum -= curRomVal;
            else
                sum += curRomVal;
        }
        
        return sum;
    }
};