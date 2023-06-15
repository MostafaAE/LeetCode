const int MAX = 500 + 1;
int memory[MAX][MAX];
string text1, text2;
class Solution {
public:
    /* 
    * Approach:
    * Dynamic Programming Memoization
    * 
    * Complexity:
    * Time Complexity : O(NM)
    * Space Complexity : O(NM) where N is text1.length, and M is text2.length
    */
    int minDistance(string word1, string word2) 
    {
        memset(memory, -1, sizeof(memory));
        text1 = word1;
        text2 = word2;
        return minDist(0, 0);
    }
    
    int minDist(int idx1, int idx2)
    {
        // if one of the strings is empty, then delete or insert the remaining of the other
        if(idx1 >= (int)text1.size() || idx2 >= (int)text2.size())
            return (int)text1.size() - idx1 + (int)text2.size() - idx2;
        
        int &ret = memory[idx1][idx2];
        if(ret != -1)
            return ret;
        
        // no operation (same letter)
        if(text1[idx1] == text2[idx2])
            return ret = minDist(idx1 + 1, idx2 + 1);
        
        int insertOp = minDist(idx1, idx2 + 1);
        int deleteOp = minDist(idx1 + 1, idx2);
        int replaceOp = minDist(idx1 + 1, idx2 + 1);
        
        return ret = 1 + min(insertOp, min(deleteOp, replaceOp));
    }
};