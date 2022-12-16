class Solution {
private:
    const static int MAX = 500 + 1;
    int memory[MAX][MAX];
    string word1, word2;
public:
    /* 
    * Approach:
    * Dynamic Programming Memoization
    * 
    * Complexity:
    * Time Complexity : O(NM)
    * Space Complexity : O(NM) where N is text1.length, and M is text2.length
    */
    int minDistance(string _word1, string _word2) 
    {
        word1 = _word1;
        word2 = _word2;
        memset(memory, -1, sizeof(memory));
        
        return editDistance(0, 0);
    }
    
    int editDistance(int idx1, int idx2)
    {
        // if one of the strings is empty, then delete or insert the remaining of the other
        if(idx1 == (int)word1.size() || idx2 == (int)word2.size())
            return ((int)word1.size()-idx1 + (int)word2.size()-idx2);
        
        int &ret = memory[idx1][idx2];
        if(ret != -1)
            return ret;
        
        // no operation (same letter)
        if(word1[idx1] == word2[idx2])
            return editDistance(idx1+1, idx2+1);
        
        // deletion
        int deleteOp = 1 + editDistance(idx1+1, idx2);
        
        // insertion
        int insertOp = 1 + editDistance(idx1, idx2+1);
        
        // change
        int changeOp = 1 + editDistance(idx1+1, idx2+1);
        
        return ret = min(deleteOp, min(insertOp, changeOp));

    }
};