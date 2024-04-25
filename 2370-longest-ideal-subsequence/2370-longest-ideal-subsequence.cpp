class Solution {
private:
    static const int MAX_IDX = 100000 + 1, MAX_CHAR = 26 + 1;
    int memory[MAX_IDX][MAX_CHAR];
    string str;
    int diff;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (pick or leave pattern)
     * Longest Increasing Subsequence (LIS) Variant
     *
     * Complexity:
     * Time Complexity : O(N)
     * Space Complexity : O(N) where N be the length of s.
     */
    int longestIdealString(string s, int k) 
    {
        memset(memory, -1, sizeof(memory));
        str = s;
        diff = k;
        return LIS(0, 26);
    }
    
    int LIS(int idx, int lastChar)
    {
        if(idx >= str.size())
            return 0;
        
        int &ret = memory[idx][lastChar];
        if(ret != -1)
            return ret;
        
        int pick{};
        if(lastChar == 26 || abs(str[idx] - (lastChar + 'a')) <= diff)
            pick = 1 + LIS(idx + 1, str[idx] - 'a');
        
        int leave = LIS(idx + 1, lastChar);
        
        return ret = max(pick, leave);
    }
};