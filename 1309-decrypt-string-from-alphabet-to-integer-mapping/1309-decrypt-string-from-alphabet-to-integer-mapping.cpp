class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    string freqAlphabets(string s) 
    {
        string result{};
        for(int i = 0 ; i < (int)s.size() ; i++)
        {
            if(i < (int)s.size() - 2 && s[i+2] == '#')
            {
                char c = s[i] == '1' ? 'j' : 'j' + 10;

                c += (s[i+1] - '0');
                
                result += c;
                i+= 2;
            }
            else
                result += ('a' + s[i] - '1');
        }
        return result;
        
    }
};