class Solution {
public:
    /**
     * Approach:
     * - If nums2.size() is odd, every element of nums1 contributes to the result.
     * - If nums1.size() is odd, every element of nums2 contributes to the result.
     * - XOR the contributions from nums1 and nums2 to get the final result.
     * 
     * Complexity:
     * - Time: O(n + m), where n and m are the sizes of nums1 and nums2 respectively.
     * - Space: O(1).
     */
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        bool isNums1Even = nums1.size() % 2 == 0;
        bool isNums2Even = nums2.size() % 2 == 0;

        int xor1 = isNums2Even ? 0 : xorAll(nums1); // XOR of nums1 if nums2.size() is odd
        int xor2 = isNums1Even ? 0 : xorAll(nums2); // XOR of nums2 if nums1.size() is odd
        
        return xor1 ^ xor2;
    }

private:
    // Helper function to compute XOR of all elements in a vector
    int xorAll(vector<int>& nums) 
    {
        int result = 0;
        for (int num : nums)
            result ^= num;
        return result;
    }
};
