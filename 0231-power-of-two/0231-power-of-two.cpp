class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    bool isPowerOfTwo(int n) 
    {
        if(n < 1)
            return false;
        
        while(n % 2 == 0)
            n /= 2;
        
        return n == 1;
    }
};