class Solution {
public:
    /* 
    * Approach: 
    * Divide and conquer
    *
    * Complexity:
    * Time Complexity : O(log(n))
    * Space Complexity : O(log(n)) => auxiliary space for stack
    */
    double myPow(double x, int n)
    {
        if(n < 0)
            x = 1 / x;

        return pow(x, llabs(n));
    }
    
    double pow(double x, long long n)
    {
        if(!n)
            return 1;
        
        double result = pow(x, n / 2);
        result *= result;
            
        // odd power
        if(n&1)
            result *= x;

        return result;
    }
};