class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        bitset<32> b(n);
        int left = 0, right = (int)b.size()-1;
        while(left < right)
        {
            int temp = b[left];
            b[left++]= b[right];
            b[right--] = temp;
        }

        return b.to_ulong(); 
    }
};