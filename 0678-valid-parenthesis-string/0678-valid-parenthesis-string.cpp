class Solution {
private:
    static const int MAX = 100 + 1;
    int memory[MAX][MAX];
    string str;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N^2)
     */
    bool checkValidString(string s) 
    {
        memset(memory, -1, sizeof(memory));
        str = s;
        
        return check(0, 0);
    }
    
    bool check(int idx, int openCount)
    {
        if(idx >= (int)str.size())
            return openCount == 0;
        
        if(openCount < 0)
            return false;
        
        int &ret = memory[idx][openCount];
        if(ret != -1)
            return ret;
        
        if(str[idx] == '(')
            return ret = check(idx + 1, openCount + 1);
        else if(str[idx] == ')')
            return ret = check(idx + 1, openCount - 1);
        
        // convert '*' to '('
        int choice1 = check(idx + 1, openCount + 1);
        // convert '*' to ''
        int choice2 = check(idx + 1, openCount);
        // convert '*' to ')'
        int choice3 = check(idx + 1, openCount - 1);
        
        return ret = choice1 || choice2 || choice3;
    }
};