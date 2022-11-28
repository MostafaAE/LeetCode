class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int lengthOfLastWord(string s) 
    {
        int cnt{},size{(int)s.size()};
        
        for(int i = size-1 ; i >= 0 ; i--)
        {
            if(s[i] != ' ')
                cnt++;
            else if(i < size-1 && s[i+1] != ' ')
                break;
        }
        
        return cnt;
    }
};