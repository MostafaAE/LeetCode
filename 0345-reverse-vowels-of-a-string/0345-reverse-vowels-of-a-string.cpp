class Solution {
public:
    /* 
    * Approach:
    * two pointers
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    string reverseVowels(string s) 
    {
        int start{}, end{(int)s.size()-1};
        
        while(start < end)
        {
            while(start < end && !isVowel(s[start]))
                start++;
            while(start < end && !isVowel(s[end]))
                end--;
            
            if(start < end)
                swap(s[start++], s[end--]);
        }
        
        return s;
    }
    
    bool isVowel(char c)
    {
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
};