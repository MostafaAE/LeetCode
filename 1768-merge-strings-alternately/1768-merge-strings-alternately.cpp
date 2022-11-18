class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(max(n,m))
    * Space Complexity : O(1) >> neglecting the output space
    */
    string mergeAlternately(string word1, string word2) 
    {
        string result{};
        int ptr1{}, ptr2{};
        
        while(ptr1+ptr2 < (int)word1.size()+(int)word2.size())
        {
            if(ptr1 < (int)word1.size())
                result += word1[ptr1++];
            
            if(ptr2 < (int)word2.size())
                result += word2[ptr2++];
        }
        
        return result;
    }
};