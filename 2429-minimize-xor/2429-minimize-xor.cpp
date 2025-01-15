class Solution {
public:
    int minimizeXor(int num1, int num2) 
    {
        int result = num1;
        int setBitsCount = numSetBits(num1);
        int targetSetBitsCount = numSetBits(num2);

        int currentBit = 0;

        while(setBitsCount < targetSetBitsCount)
        {
            if (!isSet(result, currentBit)) 
            {
                setBit(result, currentBit);
                ++setBitsCount;
            }

            currentBit++;
        }

        while(setBitsCount > targetSetBitsCount)
        {
            if (isSet(result, currentBit)) 
            {
                unsetBit(result, currentBit);
                --setBitsCount;
            }

            currentBit++;
        }

        return result;
    }

    // Helper function to get the count of set bits
    int numSetBits(int num)
    {
        int count{};
        while(num)
            count += num & 1, num >>= 1;

        return count;
    }

    // Helper function to check if the given bit position in x is set (1).
    bool isSet(int x, int bit) { return x & (1 << bit); }

    // Helper function to set the given bit position in x to 1.
    void setBit(int &x, int bit) { x |= (1 << bit); }

    // Helper function to unset the given bit position in x (set it to 0).
    void unsetBit(int &x, int bit) { x &= ~(1 << bit); }
};
