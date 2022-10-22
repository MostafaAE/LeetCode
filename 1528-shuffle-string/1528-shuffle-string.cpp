class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    string restoreString(string s, vector<int>& indices) 
    {
        string restored = s;
        for(int i = 0 ; i < (int)s.size() ; i++)
            restored[indices[i]] = s[i];
        
        return restored;
    
    }
};