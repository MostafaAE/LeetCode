class Solution {
public:
    /* 
    * Approach: 
    * Use a hashmap to map each alien character to its index, then compare every two consecutive strings to check if they are sorted lexicographically.
    *
    * Complexity:
    * Time Complexity : O(N*L)
    * Space Complexity : O(1)
    */
    bool isAlienSorted(vector<string>& words, string order) 
    {
        unordered_map<char, int> charToIdx;
        for(int i = 0 ; i < (int)order.size() ; i++)
        {
            charToIdx[order[i]] = i;
        }
        
        for(int i = 1 ; i < (int)words.size() ; i++)
        {
            if(!isSorted(words[i - 1] , words[i], charToIdx))
                return false;
        }
        
        return true;
    }
    
    bool isSorted(string &a, string &b, unordered_map<char, int>& charToIdx)
    {
        int s1 = a.size(), s2 = b.size();
        
        for(int i = 0 ; i < min(s1, s2) ; i++)
        {
            if(a[i] != b[i])
                return charToIdx[a[i]] < charToIdx[b[i]];
        }
        
        return s1 <= s2;
    }
};