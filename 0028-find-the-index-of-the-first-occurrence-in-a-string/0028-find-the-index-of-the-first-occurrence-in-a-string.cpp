class Solution {
public:
    /* 
    * Approach:
    * string matching using two pointers
    * 
    * Complexity:
    * Time Complexity : O(L) where L is haystack.length
    * Space Complexity : O(1)
    */
    int strStr(string haystack, string needle) 
    {
        if(needle.size() > haystack.size())
            return -1;
        
        int firstOccurance{-1};
        bool found{};
        for(int i = 0, j = 0 ; i < (int)haystack.size() ; i++)
        {
            if(haystack[i] == needle[j])
            {
                if(!j)
                    firstOccurance = i;
                
                if(j == needle.size()-1)
                {
                    found = 1; 
                    break;
                }
                
                j++;
            }
            else if(j)
            {
                j = 0;
                i = firstOccurance;
            }
        }
        
        if(found)
            return firstOccurance;
        return -1;
    }
};