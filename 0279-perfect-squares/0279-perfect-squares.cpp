const int MAX = 10000 + 1;
int memory[MAX];

class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     *
     * Complexity:
     * Time Complexity : O(n*sqrtn)
     * Space Complexity : O(n)
     */
    int numSquares(int n) 
    {
        memset(memory, -1, sizeof(memory));
        return minSquares(n);
    }
    
    int minSquares(int n)
    {
        if(n <= 1)
            return n;
        
        int &ret = memory[n];
        if(ret != -1)
            return ret;

        ret = n;
        for(int i = 1 ; i * i <= n ; i++)
            ret = min(ret, 1 + minSquares(n - i*i));

        return ret;
    }
};