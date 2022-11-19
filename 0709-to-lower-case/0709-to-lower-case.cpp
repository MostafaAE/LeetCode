class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    string toLowerCase(string s) 
    {
        for(int i = 0 ; i < (int)s.size() ; i++)
            if('A' <= s[i] && s[i] <= 'Z')
                s[i] += ('a' - 'A');
        return s;
    }
};