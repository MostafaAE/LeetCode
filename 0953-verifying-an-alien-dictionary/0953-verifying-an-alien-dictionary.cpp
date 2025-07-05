class Solution {
public:
    /* 
    * Approach: 
    * Use a hashmap to map each alien character to its index, then compare every two consequetive strings to check if they are sorted lexicographically.
    *
    * Complexity:
    * Time Complexity : O(N*L)
    * Space Complexity : O(1)
    */
    bool isAlienSorted(vector<string>& words, string order) 
    {
        unordered_map<char, int> charToIdx;
        
        for(int i = 0 ; i < (int)order.size() ; i++)
            charToIdx[order[i]] = i;
        
        for(int i = 1 ; i < (int)words.size() ; i++)
        {
            int s1 = words[i-1].size(), s2 = words[i].size(), equals{};
            
            for(int j = 0 ; j < min(s1, s2) ; j++)
            {
                if(charToIdx[words[i-1][j]] < charToIdx[words[i][j]])
                    break;
                else if(charToIdx[words[i-1][j]] > charToIdx[words[i][j]])
                    return false;
                else
                    equals++;
            }
            if(equals == s2 && s1 > s2)
                return false;
        }
        
        return true;
    }
};