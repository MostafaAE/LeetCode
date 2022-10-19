class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(L)
    * Space Complexity : O(1)
    */
    bool isIsomorphic(string s, string t) 
    {
        vector<int> mapping (256, -1);
        
        for(int i = 0 ; i < (int)s.size() ; i++)
        {
            if(mapping[s[i]] == -1 && mapping[128+t[i]] == -1)
            {
                mapping[s[i]] = t[i];
                mapping[128+t[i]] = s[i];
            }
            else if(mapping[s[i]] != t[i] || mapping[128+t[i]] != s[i])
                return false;
        }
        return true;
    }
};