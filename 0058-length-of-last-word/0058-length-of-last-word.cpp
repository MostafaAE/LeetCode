class Solution {
public:
    /* 
    * Approach:
    * Iterate through the string in reverse. Upon encountering the first non-space character, identify it as the end of the last word. Continue iterating until a space character or the string's beginning is reached. 
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int lengthOfLastWord(string s) 
    {
        int wordEnd{-1};
        for(int i = s.size()-1 ; i >= 0 ; i--)
        {
            if(s[i] != ' ' && wordEnd == -1)
                wordEnd = i;
            else if(s[i] == ' ' && wordEnd != -1)
                return wordEnd - i;
        }
        return wordEnd + 1;
    }
};