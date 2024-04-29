class Solution {
public:
    /* 
    * Approach:
    * - Calculate the XOR of all elements in the array.
    * - Count the number of set bits in the XOR result.
    *
    * Complexity:
    * Time Complexity: O(n)
    * Space Complexity: O(1)
    */
    int minOperations(vector<int>& nums, int k) 
    {
        int xorRes{k}, count{};
        
        // Calculate the XOR of all elements in the array
        for(int num : nums)
            xorRes ^= num;
        
        // Count the number of set bits in the XOR result
        // We can also use popcount(xorRes)
        while(xorRes)
        {
            count += xorRes & 1;
            xorRes >>= 1;
        }
        
        return count;
    }
};
