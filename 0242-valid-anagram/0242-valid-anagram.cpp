class Solution {
public:
    /* 
    * Approach:
    * store the frequency of each letter in each string
    * compare the letter frequencies of the two strings
    *
    * Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
    * Use a hash table instead of array of 26 elements to count each character
    *
    * Complexity:
    * Time Complexity : O(L)
    * Space Complexity : O(1)
    */
    bool isAnagram(string s, string t) 
    {
        if((int)s.size() != (int)t.size())
            return false;
        
        unordered_map<char, int> count1, count2;
        
        // O(L) => L = s.length = t.length
        for(int i = 0 ; i < (int)s.size() ; i++)
            count1[s[i]]++, count2[t[i]]++;
        
        // O(1)
        for(int i = 'a' ; i < 'z' ; i++)
            if(count1[i] != count2[i])
                return false;
        
        return true;
    }
};