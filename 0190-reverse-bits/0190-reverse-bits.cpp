class Solution {
public:
    /* 
    * Approach:
    * Bit manipulation
    * 
    * Complexity:
    * Time Complexity : O(1)
    * Space Complexity : O(1)
    */
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t result{};
        for(int i = 0 ; i < 32 ; i++)
        {
            result <<= 1;
            result |= (n&1);
            n >>= 1;
        }

        return result; 
    }
};