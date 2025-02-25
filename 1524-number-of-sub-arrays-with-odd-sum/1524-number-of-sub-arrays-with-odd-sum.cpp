class Solution {
public:
    /**
     * Approach:
     * - Maintain a `prefixSum` to track the sum of elements encountered so far.
     * - Use `oddCount` to store the number of subarrays with an odd sum.
     * - Use `evenCount` to store the number of subarrays with an even sum.
     * - Initialize `evenCount = 1` because an empty subarray (sum = 0) is considered even.
     * - Iterate through the array:
     *   - If `prefixSum` becomes odd, add `evenCount` to `result` and increment `oddCount`.
     *   - If `prefixSum` becomes even, add `oddCount` to `result` and increment `evenCount`.
     * - Apply modulo `1e9 + 7` to prevent overflow.
     * 
     * Complexity:
     * - **Time Complexity:** O(n)
     * - **Space Complexity:** O(1)
     */
    int numOfSubarrays(vector<int>& arr) 
    {
        const int MOD = 1e9 + 7;
        int prefixSum = 0, result = 0;
        int oddCount = 0, evenCount = 1;  // Even count initialized to 1 for the empty prefix sum case

        for (int num : arr)
        {
            prefixSum += num;
            
            if (prefixSum & 1)  // If prefixSum is odd
            {
                result += evenCount;
                ++oddCount;
            }
            else  // If prefixSum is even
            {
                result += oddCount;
                ++evenCount;
            }

            result %= MOD;
        }

        return result;
    }
};