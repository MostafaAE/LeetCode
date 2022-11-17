class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        for(int i = 0 ; i < 16 ; i++)
        {
            int curLeftBit = getBit(n, i);
            int curRightBit = getBit(n, 31-i);
            
            curLeftBit ? setBit1(n, 31-i) : setBit0(n, 31-i);
            curRightBit ? setBit1(n, i) : setBit0(n, i);
        }

        return n; 
    }
    
    int getBit(uint32_t n, int idx)
    {
        return ((n >> idx)&1) == 1;
    }
    
    void setBit1(uint32_t &n, int idx)
    {
        n |= (1 << idx);
    }
    
    void setBit0(uint32_t &n, int idx)
    {
        n &= ~(1 << idx);
    }
};