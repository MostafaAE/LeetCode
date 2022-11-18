class Solution {
public:
     /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    char findTheDifference(string s, string t) 
    {
        char diff{};
        
        for(int i = 0 ; i < (int)s.size() ; i++)
            diff ^= s[i], diff ^= t[i];
        diff ^= t[(int)t.size()-1];
        
        return diff;
    }
};