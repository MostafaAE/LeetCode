class Solution {
public:
    /* 
    * Approach:
    * iterate over the input string while storing the frequency of each letter
    * if the frequency of any letter exceded 1 return that letter
    * 
    * Complexity:
    * Time Complexity : O(L)
    * Space Complexity : O(1)
    */
    char repeatedCharacter(string s) 
    {
        int freq[26]{};
        char res;
        
        //O(L)
        for(char c : s)
        {
            if(++freq[c - 'a'] == 2)
            {
                res = c;
                break;
            }
        }
        
        return res;     
    }
};