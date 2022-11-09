class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    bool isPowerOfThree(int n) 
    {
        if(n < 1)
            return false;
        
        while(n % 3 == 0)
            n/=3;
        
        return n == 1;
    }
};