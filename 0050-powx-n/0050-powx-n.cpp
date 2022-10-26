class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(logn) => auxiliary space for stack
    */
    double myPow(double x, int n) 
    {
        if(n < 0)
            x = 1/x;
        
        long long num = llabs(n);
        
        if(num == 0)
            return 1;
        
        double pow = myPow(x, num/2);

        // odd
        if(num&1)
            return x * pow * pow;
        else
            return pow * pow;
    }
};