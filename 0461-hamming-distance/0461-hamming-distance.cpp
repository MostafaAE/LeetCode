class Solution {
public:
    /*
     * Approach
     * Use bitwise operations to compare corresponding bits of x and y while shifting them right by 1 bit each time, counting the differing bits.
     *
     * Complexity:
     * Time Complexity : O(1) (since we're only considering 32 bits)
     * Space Complexity : O(1)
     */
    int hammingDistance(int x, int y) 
    {
        int count{};
        
        while(x || y)
        {
            int rightMostX = x & 1;
            int rightMostY = y & 1;
            count += (rightMostX != rightMostY);
            
            x = x >> 1;
            y = y >> 1;
        }
        
        return count;
    }
};