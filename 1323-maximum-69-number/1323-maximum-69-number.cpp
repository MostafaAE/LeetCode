class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(L)
    * Space Complexity : O(L)
    */
    int maximum69Number (int num) 
    {
        string s = to_string(num);
        
        for(int i = 0 ; i < (int)s.size() ; i++)
        {
            if(s[i] == '6')
            {
                s[i] = '9';
                break;
            }
        }
        
        return stoi(s); 
    }
};