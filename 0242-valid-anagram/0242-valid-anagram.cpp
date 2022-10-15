class Solution {
public:
    
    /* 
    * Approach:
    * sort the two strings and compare them
    * 
    * Complexity:
    * Time Complexity : O(L*log(L))
    * Space Complexity : O(1)
    */
    bool isAnagram(string s, string t) 
    {
        if((int)s.size() != (int)t.size())
            return false;
        
        // O(L*log(L)) => L = s.length = t.length
        sort(s.begin(), s.end());
        // O(L*log(L))
        sort(t.begin(), t.end());
        
        // O(L)
        return s == t;
        
    }
};