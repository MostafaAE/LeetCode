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
    int tribonacci(int n) 
    {
        if(n <= 0)
            return 0;
        if(n <= 2)
            return 1;
        
        int a{}, b{1}, c{1}, res;
        for(int i = 3 ; i <= n ; i++)
        {
            res = a + b + c;
            a = b;
            b = c;
            c = res;
        }
        
        return res;
    }
};