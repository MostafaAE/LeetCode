class Solution {
private:
    static const int MAX = 500 + 1;
    int memory[MAX][MAX];
    vector<int> numsg1, numsg2;
public:
    /* 
    * Approach:
    * Dynamic Programming Memoization (pick or leave approach)
    * 
    * Complexity:
    * Time Complexity : O(NM)
    * Space Complexity : O(NM) where N is nums1.length, and M is nums2.length
    */
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        numsg1 = nums1;
        numsg2 = nums2;
        memset(memory, -1, sizeof(memory));
        
        return LCS(0, 0);
    }
    
    int LCS(int idx1, int idx2)
    {
        if(idx1 >= numsg1.size() || idx2 >= numsg2.size())
            return 0;
        
        int &ret = memory[idx1][idx2];
        if(ret != -1)
            return ret;
        
        // pick from both
        if(numsg1[idx1] == numsg2[idx2])
            return ret =1 + LCS(idx1 + 1, idx2 + 1);
        // leave
        int choice1 = LCS(idx1 + 1, idx2);
        int choice2 = LCS(idx1, idx2 + 1);
        
        return ret = max(choice1, choice2);
    }
};