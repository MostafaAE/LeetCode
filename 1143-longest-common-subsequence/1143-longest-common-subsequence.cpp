const int MAX = 1000 + 1;
int memory[MAX][MAX];
string text1, text2;
class Solution {
public:
    /* 
    * Approach:
    * Dynamic Programming Memoization (pick or leave approach)
    * 
    * Complexity:
    * Time Complexity : O(NM)
    * Space Complexity : O(NM) where N is text1.length, and M is text2.length
    */
    int longestCommonSubsequence(string text_1, string text_2) 
    {
        memset(memory, -1, sizeof(memory));
        text1 = text_1;
        text2 = text_2;
        
        return LCS(0, 0);
    }
    
    int LCS(int idx1, int idx2)
    {
        if(idx1 >= (int)text1.size() || idx2 >= (int)text2.size())
            return 0;
        
        int &ret = memory[idx1][idx2];
        if(ret != -1)
            return ret;
        
        // pick from both
        if(text1[idx1] == text2[idx2])
            return ret = 1 + LCS(idx1 + 1, idx2 + 1);
        // leave from text1
        int choice1 = LCS(idx1 + 1, idx2);
        
        // leave from text2
        int choice2 = LCS(idx1, idx2 + 1);
        
        return ret = max(choice1, choice2);
    }
};