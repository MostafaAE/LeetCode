class Solution {
private:
    const static int MAX = 10000 + 1;
    int memory[MAX];
    
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
        return perfectSquares(n);
    }
    
    int perfectSquares(int n)
    {
        if(n <= 0)
            return 0;
        
        int &ret = memory[n];
        if(ret != -1)
            return ret;
        
        ret = n;
        for(int i = 1 ; i*i <= n ; i++)
                ret = min(ret, 1 + perfectSquares(n-i*i));
        
        return ret;
    }
};