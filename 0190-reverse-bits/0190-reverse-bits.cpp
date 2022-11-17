class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t result{};
        for(int i = 0 ; i < 32 ; i++)
        {
            int curMostRight = n&1;
            result <<= 1;
            result |= curMostRight;
            n >>= 1;
        }

        return result; 
    }
};