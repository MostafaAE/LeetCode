const int MAX = 500 + 1;
int memory[MAX][MAX];
string str;

class Solution {
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
        return minSteps(0, (int)str.size() - 1);
    }
    
    int minSteps(int start, int end)
    {
        if(start >= end)
            return 0;
        
        int &ret = memory[start][end];
        if(ret != -1)
            return ret;
        
        if(str[start] == str[end])
            return ret = minSteps(start + 1, end - 1);
        
        int insertLeft = minSteps(start, end - 1);
        int insertRight = minSteps(start + 1, end);
        
        return ret = 1 + min(insertLeft, insertRight);
    }
};