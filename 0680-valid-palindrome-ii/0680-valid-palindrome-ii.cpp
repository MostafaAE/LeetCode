class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(L)
    * Space Complexity : O(1)
    */
    bool validPalindrome(string s) 
    {
        int start{};
        int end{(int)s.size()-1};
        
        while(start < end)
        {
            if(s[start] != s[end])
                return isPalindrome(s, start+1 , end) || isPalindrome(s, start , end-1);
            else
                start++, end--;    
            
        }
        return true;
    }
    
    bool isPalindrome(const string &s, int start, int end)
    {
        while(start < end)
            if(s[start++] != s[end--])
                return false;
        
        return true;
    }
};