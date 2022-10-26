class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(logn) => auxiliary space for stack
    */
    double myPow(double x, long long n) 
    {
        if(n < 0)
            n = -n, x = 1/x;
        
        if(n == 0)
            return 1;
        
        double pow = myPow(x, n/2);

        // odd
        if(n&1)
            return x * pow * pow;
        else
            return pow * pow;
    }
};