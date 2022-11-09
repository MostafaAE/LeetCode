class Solution {
public:
    /* 
    * Approach:
    * bit manipulation
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int hammingWeight(uint32_t n) 
    {
        int count{};
        while(n)
        {
            // check if rightmost bit is 1 (odd number)
            if(n&1)
                count++;
            // shift right (divide by 2)
            n = n>>1;
        }
        return count;
    }
};