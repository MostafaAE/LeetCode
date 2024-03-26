class Solution {
public:
    /* 
    * Approach:
    * Iterate over both strings in reverse, ignoring characters removed by backspaces ('#'). 
    * Compare corresponding valid characters from both strings. Continue this comparison until either of the strings ends.
    * 
    * Complexity:
    * Time Complexity : O(n) => where n is the maximum length between the two input strings
    * Space Complexity : O(1)
    */
    bool backspaceCompare(string s, string t) 
    {
        int idx1{(int)s.size()-1}, idx2{(int)t.size()-1};
        while(idx1 >= 0 || idx2 >= 0)
        {
            idx1 = nextValidIdx(s, idx1);
            idx2 = nextValidIdx(t, idx2);
            
            char c1 = idx1 >= 0 ? s[idx1] : ' ';
            char c2 = idx2 >= 0 ? t[idx2] : ' ';

            if(c1 != c2)
                return false;

            idx1--, idx2--;
        }
        
        return true;
    }
    
    int nextValidIdx(string& str, int idx)
    {
        int skip{};
        while(idx >= 0)
        {
            if(str[idx] == '#')
                skip++;
            else if(skip)
                skip--;
            else
                break;
            idx--;
        }
        return idx;
    }
    
};