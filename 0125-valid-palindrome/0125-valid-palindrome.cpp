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
        
        while(start < end)
        {
            while(start < end && !isalnum(s[start]))
                start++;
            
            while(start < end && !isalnum(s[end]))
                end--;
            
            if(start < end && tolower(s[start++]) != tolower(s[end--]))
                return false;
        }
        
        return true;
    }
};