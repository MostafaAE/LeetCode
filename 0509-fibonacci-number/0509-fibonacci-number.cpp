class Solution {
public:
    /* 
    * Approach: 
    * Iterative approach
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int fib(int n) {
        if(n <= 1)
            return n;
        
        int a{}, b{1}, c;
        
        for(int i = 2 ; i <= n ; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
    }
};