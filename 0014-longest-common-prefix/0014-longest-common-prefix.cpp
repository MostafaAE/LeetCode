class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(NL)
    * Space Complexity : O(L)
    */
    string longestCommonPrefix(vector<string>& strs) 
    {
        string curLongestPrefix = strs[0];
        
        for(int i = 1 ; i < (int)strs.size() ; i++)
        {
            string curPrefix{};
            
            int minSz = min((int)strs[i].size() , (int)curLongestPrefix.size());
                
            for(int j = 0 ; j < minSz ; j++)
            {
                if(curLongestPrefix[j] == strs[i][j])
                    curPrefix += curLongestPrefix[j];
                else
                    break;
            }
        
            curLongestPrefix = curPrefix;
        }
        return curLongestPrefix;
    }
};