const int MAX = 100 + 1;
int memory[MAX];
string str;
class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Counting DP
     *
     * Complexity:
     * Time Complexity : O(N)
     * Space Complexity : O(N)
     */
    int numDecodings(string s) 
    {
        memset(memory, -1, sizeof(memory));
        str = s;
        return decodeWays(0);
    }

    int decodeWays(int idx) 
    {
        // valid way
        if(idx >= (int)str.size())
            return 1;
        
        // invalid way
        if(str[idx] == '0')
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        ret = decodeWays(idx + 1);
        if(idx < (int)str.size() - 1 && (str[idx] == '1' || (str[idx] == '2' && str[idx + 1] <= '6') ))
            ret += decodeWays(idx + 2);

        return ret;
    }
};