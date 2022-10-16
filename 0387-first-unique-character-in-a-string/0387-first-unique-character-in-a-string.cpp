class Solution {
public:
    /* 
    * Approach:
    * store the frequency of each letter in the string
    * return the index of the first letter with frequency == 1
    * 
    * Complexity:
    * Time Complexity : O(L)
    * Space Complexity : O(1)
    */
    int firstUniqChar(string s) {
        
        unordered_map<int, int> um;
        
        for(int i = 0 ; i < (int)s.size() ; i++)
            um[s[i]-'a']++;
        
        for(int i = 0 ; i < (int)s.size() ; i++)
            if(um[s[i]-'a'] == 1)
                return i;
        
        return -1; 
    }
};