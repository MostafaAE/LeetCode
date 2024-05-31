class Solution {
public:
    /*
    * Approach:
    * - XOR all the numbers to get the XOR result of the two unique numbers.
    * - Find a bit that is set in the XOR result, which indicates a bit where the two unique numbers differ.
    * - Use this set bit to partition the numbers into two groups, one with the bit set and one with the bit not set.
    * - XOR all numbers in each group to get the two unique numbers.
    *
    * Complexity:
    * - Time Complexity: O(n)
    * - Space Complexity: O(1)
    */
    vector<int> singleNumber(vector<int>& nums) 
    {
        int xorResult = 0, differentBit = 1, group1 = 0, group2 = 0;
        
        // Step 1: XOR all numbers to get the XOR of the two unique numbers
        for (auto val : nums)
            xorResult ^= val;
        
        // Step 2: Find a set bit in the XOR result
        // This bit is different between the two unique numbers
        while (!(xorResult & differentBit))
            differentBit <<= 1;
        
        // Step 3: Partition the numbers into two groups and XOR each group
        for (auto val : nums)
        {
            if (val & differentBit)
                group1 ^= val;
            else
                group2 ^= val;
        }

        // Step 4: The result is the two unique numbers
        return {group1, group2};
    }
};
