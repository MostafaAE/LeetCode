class Solution {
public:
     /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) >> constant space (26 characters only)
    */
    char findTheDifference(string s, string t) 
    {
        unordered_map<int,int> count;
        
        for(int i = 0 ; i < (int)s.size() ; i++)
            count[s[i]]++, count[t[i]]++;
        
        count[t[(int)t.size()-1]]++;
        
        for(auto &p : count)
            if(p.second&1) // odd
                return p.first;
        
        return ' ';
    }
};