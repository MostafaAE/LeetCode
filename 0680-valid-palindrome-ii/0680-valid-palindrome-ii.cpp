class Solution {
public:
    /* 
    * Approach:
    * Two pointers approach, when we encounter two different characters attempt the following:
    * 1. Delete the character at the 'left' pointer and continue checking for palindrome
    * 2. Delete the character at the 'right' pointer and continue checking for palindrome
    * 
    * Complexity:
    * Time Complexity : O(L)
    * Space Complexity : O(1)
    */
    bool validPalindrome(string s) 
    {
        int left{}, right{(int)s.size() - 1};
        
        while(left < right)
        {
            if(s[left] != s[right])
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            else
                ++left, --right;
        }
        
        return true;
    }
    
    bool isPalindrome(string& s, int left, int right)
    {
        while(left < right)
            if(s[left++] != s[right--])
                return false;
        return true;
    }
};