class Solution {
public:
    /* 
    * Approach:
    * iterate over the input string using two pointers (start, end)
    * compare every two alphanumeric characters together and ignore all non-alphanumeric characters
    * 
    * Complexity:
    * Time Complexity : O(L)
    * Space Complexity : O(1)
    */
    bool isPalindrome(string s) 
    {
        int start = 0;
        int end = (int)s.size()-1;
        
        while(start <= end)
        {
            if(!isalnum(s[start]))
                start++;
            if(!isalnum(s[end]))
                end--;
            
            if(isalnum(s[start]) && isalnum(s[end]) 
               && tolower(s[start++]) != tolower(s[end--]))
                return false;
        }
        
        return true;
    }
};