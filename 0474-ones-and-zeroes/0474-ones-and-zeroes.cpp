class Solution {
private:
    static const int MAX_LEN = 600 + 1, MAX = 100 + 1;
    int memory[MAX_LEN][MAX][MAX];
    vector<string> strs;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (Knapsack variant => pick or leave pattern)
     *
     * Complexity:
     * Time Complexity : O(LKMN)
     * Space Complexity : O(LMN) where L is the number of strs, K is the length of maximum string in str,  M is the number of zeros, N is the number of ones.
     */
    int findMaxForm(vector<string>& _strs, int m, int n) 
    {
        memset(memory, -1, sizeof(memory));
        strs = _strs;
        return findMax(0, m, n);
    }
    
    int findMax(int idx, int zeros, int ones)
    {
        if(idx >= (int)strs.size())
            return 0;
        
        int &ret = memory[idx][zeros][ones];
        if(ret != -1)
            return ret;
        
        int zerosCount{}, onesCount{};
        for(int i = 0 ; i < (int)strs[idx].size() ; i++)
        {
            if(strs[idx][i] == '0')
                zerosCount++;
            else
                onesCount++;
        }
        
        // pick option
        int pick{};
        if(zerosCount <= zeros && onesCount <= ones)
            pick = 1 + findMax(idx + 1, zeros - zerosCount, ones - onesCount);
        
        // leave option
        int leave = findMax(idx + 1, zeros, ones);
        
        return ret = max(pick, leave);
    }
    
};