class Solution {
private:
    static const int MAX = 500 + 1;
    int memory[MAX][MAX];
    string str;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Range pattern
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N^2) where N is the max index
     */
    int minInsertions(string s) 
    {
        str = s;
        memset(memory, -1, sizeof(memory));
        return minSteps(0, (int)s.size()-1);
    }
    
    int minSteps(int startIdx, int endIdx)
    {
        if(startIdx >= endIdx)
            return 0;
        
        int &ret = memory[startIdx][endIdx];
        if(ret != -1)
            return ret;
        
        if(str[startIdx] == str[endIdx])
            return ret = minSteps(startIdx + 1, endIdx - 1);
        
        int insertFront = 1 + minSteps(startIdx, endIdx-1);
        int insertBack = 1 + minSteps(startIdx + 1, endIdx);
        
        return ret = min(insertFront, insertBack);
    }
};