class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    bool isPowerOfFour(int n) 
    {
        if(n < 1)
            return false;
        
        while(n % 4 == 0)
            n /= 4;
        
        return n == 1;
        
    }
};