class Solution {
public:
    /* 
    * Approach: 
    * Utilize a hash map to make sure that a character always maps to the same character.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) 
    */
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashMap1, hashMap2;
        
        for(int i = 0 ; i < (int)s.size() ; i++)
        {
            if(hashMap1.contains(s[i]) && hashMap1[s[i]] != t[i] || hashMap2.contains(t[i]) && hashMap2[t[i]] != s[i])
                return false;
            hashMap1[s[i]] = t[i];
            hashMap2[t[i]] = s[i];
        }
        
        return true;
    }
};