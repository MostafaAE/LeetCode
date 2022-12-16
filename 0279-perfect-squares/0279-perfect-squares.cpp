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
     * Time Complexity : O(N^2)
     * Space Complexity : O(N)
     */
    int numSquares(int n) 
    {
        memset(memory, -1, sizeof(memory));
        return perfectSquareSum(n);
    }
    
    int perfectSquareSum(int n)
    {
        int &ret = memory[n];
        if(ret != -1)
            return ret;
        
        if(isPerfectSquare(n))
            return 1;
        
        ret = n;
        for(int i = 1 ; i < n ; i++)
            if(isPerfectSquare(i))
                ret = min(ret, 1 + perfectSquareSum(n-i));
        
        return ret;
    }
    
    bool isPerfectSquare(int n)
    {
        int sr = sqrt(n);
        return sr*sr == n;
    }
};