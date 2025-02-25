class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    /**
     * Approach:
     * 1. Maintain two arrays:
     *    - `evenCount[i]`: Number of subarrays ending at index `i` with an even sum.
     *    - `oddCount[i]`: Number of subarrays ending at index `i` with an odd sum.
     * 2. Iterate through the array and update the counts:
     *    - Every new element increases the count of even subarrays.
     *    - If the element is odd, swap the `oddCount` and `evenCount` values at that index.
     * 3. Sum all values in `oddCount[]` to get the total number of subarrays with an odd sum.
     *
     * Complexity:
     * - Time Complexity: O(n) since we iterate through `arr` twice.
     * - Space Complexity: O(n) due to `oddCount` and `evenCount` arrays.
     */
    int numOfSubarrays(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> oddCount(n, 0), evenCount(n, 0);

        // Initialize the first element
        (arr[0] & 1) ? ++oddCount[0] : ++evenCount[0];

        // Populate oddCount and evenCount arrays
        for (int i = 1; i < n; ++i)
        {
            evenCount[i] = evenCount[i - 1] + 1;
            oddCount[i] = oddCount[i - 1];

            // If arr[i] is odd, swap counts
            if (arr[i] & 1)
                swap(oddCount[i], evenCount[i]);
        }

        // Compute the final result
        int result = 0;
        for (int i = 0; i < n; ++i)
            result = (result + oddCount[i]) % MOD;

        return result;
    }
};
