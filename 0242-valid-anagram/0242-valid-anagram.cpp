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
        // O(L*log(L))
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // O(L)
        return s == t;
        
    }
};