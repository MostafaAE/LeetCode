class Solution {
public:
    /* 
    * Approach:
    * iterate on each number started from 0 to the squre root of c to check if there is a valid two integer
    * 
    * Complexity:
    * Time Complexity : O(sqrt(c)log(c))
    * Space Complexity : O(1)
    */
    bool judgeSquareSum(int c) 
    {
        
        for(long long a = 0 ; a*a <= c ; a++)
            if(isValid(c,a))
                return true;
        
        return false;
    }
    
    bool isValid(int c, int a)
    {
        double b = sqrt(c-a*a);
        
        // true if b is integer
        return (trunc(b) == b);
        
    }
};