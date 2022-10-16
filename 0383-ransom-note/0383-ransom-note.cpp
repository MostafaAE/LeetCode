class Solution {
public:
    /* 
    * Approach:
    * store the frequency of each letter in each string
    * compare the letter frequencies of the two strings
    * if frequency of all letters in ransomNote <= frequency of all letter in magazine
    * then this is a valid ransomNote
    * 
    * Complexity:
    * Time Complexity : O(m+r)
    * Space Complexity : O(1)
    */
    bool canConstruct(string ransomNote, string magazine) 
    {
        int m = (int)magazine.size();
        int r = (int)ransomNote.size();
        if(m < r)
            return false;
        
        unordered_map<int, int> mFreq, rFreq;
        
        // O(m)
        for(int i = 0 ; i < m ; i++)
            mFreq[magazine[i]-'a']++;
        
        // O(r)
        for(int i = 0 ; i < r ; i++)
            rFreq[ransomNote[i]-'a']++;
        
        //O(1)
        for(int i = 0 ; i < 26 ; i++)
            if(rFreq[i] > mFreq[i])
                return false;

        return true;
        
    }
};