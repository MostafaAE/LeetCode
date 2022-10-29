class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(NL)
    * Space Complexity : O(1)
    */
    string longestCommonPrefix(vector<string>& strs) 
    {
        int ans = strs[0].size();
        
        for(int i = 1 ; i < (int)strs.size() ; i++)
        {
            int minSize = min((int)strs[i].size() , ans);
            
            int j = 0;
            while(j < minSize && strs[0][j] == strs[i][j]) 
                j++;
            
            ans = min(ans, j);
        }
        
        return strs[0].substr(0, ans);;
    }
};