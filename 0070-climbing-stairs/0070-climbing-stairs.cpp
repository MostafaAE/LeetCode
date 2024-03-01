class Solution {
public:
    /* 
    * Approach: 
    * DP Tabulation (Fibonacci style)
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int climbStairs(int n) 
    {
        if(n <= 2)
            return n;
        
        int a = 1, b = 2, c;
        
        for(int i = 3 ; i <= n ; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
    }
};