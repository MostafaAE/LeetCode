class Solution {
public:
    /* 
    * Approach:
    * Two pointers approach.
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    bool checkValidString(string s) 
    {
        int openBrackets{}, closedBrackets{}, n{(int)s.size()};
        
        for(int idx = 0 ; idx < n ; idx++)
        {
            if(s[idx] == '(' || s[idx] == '*')
                ++openBrackets;
            else
                --openBrackets;
            
            if(s[n-idx-1] ==  ')' || s[n-idx-1] == '*')
                ++closedBrackets;
            else
                --closedBrackets;
            
            if(openBrackets < 0 || closedBrackets < 0)
                return false;
        }
        
        return true;
    }
};