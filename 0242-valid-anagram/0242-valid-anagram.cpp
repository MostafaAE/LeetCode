class Solution {
public:
    
    /* 
    * Approach:
    * store the frequency of each letter in each string
    * compare the letter frequencies of the two strings
    * 
    * Complexity:
    * Time Complexity : O(L)
    * Space Complexity : O(1)
    */
    bool isAnagram(string s, string t) 
    {
        if((int)s.size() != (int)t.size())
            return false;
        
        int sFreq[26]{}, tFreq[26]{};
        
        // O(L) => L = s.length = t.length
        for(int i = 0 ; i < (int)s.size() ; i++)
        {
            sFreq[s[i]-'a']++;
            tFreq[t[i]-'a']++;
        }
        
        // O(1)
        for(int i = 0 ; i < 26 ; i++)
            if(sFreq[i] != tFreq[i])
                return false;
        
        return true;
        
    }
};