const int MAX = 58 + 1;
int memory[MAX];
class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N)
     */
    int integerBreak(int n) 
    {
        if(n <= 3)
            return n - 1;
        memset(memory, -1, sizeof(memory));
        return maxProduct(n);
    }
    
    int maxProduct(int n)
    {
        if(n == 1)
            return 1;
        
        int &ret = memory[n];
        if(ret != -1)
            return ret;
        
        ret = n;
        for(int i = 1 ; i < n ; i++)
            ret = max(ret, i * maxProduct(n-i));
        
        return ret;
    }
};