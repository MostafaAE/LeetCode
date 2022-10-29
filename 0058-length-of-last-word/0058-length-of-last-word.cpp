class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(L)
    * Space Complexity : O(1)
    */
    int lengthOfLastWord(string s) 
    {
        int cnt{};
        
        for(int i = 0 ; i < (int)s.size() ; i++)
        {
            if(isalpha(s[i]))
            {
                if(i > 0 && s[i-1] == ' ')
                    cnt = 0;
                cnt++;
            }         
        }
        
        return cnt;
    }
};