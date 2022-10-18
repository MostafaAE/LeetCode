class Solution {
public:
    /* 
    * Approach:
    * Convert the integer to a string and check if it is a palindrome
    * 
    * Complexity:
    * Time Complexity : O(L) where L is the number of digits in the input
    * Space Complexity : O(L)
    */
    bool isPalindrome(int x) 
    {
        if(x < 0)
            return false;
        
        string s = to_string(x);
        int start{}, end = (int)s.size()-1;
        
        while(start < end)
            if(s[start++] != s[end--])
                return false;
        
        return true;
        
    }
};