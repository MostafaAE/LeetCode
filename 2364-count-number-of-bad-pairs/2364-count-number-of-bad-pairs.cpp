class Solution {
public:
    /**
     * Approach:
     * 1. To identify bad pairs, we first recognize that a "good pair" satisfies the condition:
     *    `j - nums[j] == i - nums[i]`.
     *    This can be rephrased as finding pairs where the difference `i - nums[i]` is the same for both indices.
     * 2. Instead of counting bad pairs directly, count the total number of good pairs and subtract this from the total number of pairs:
     *    - Total pairs = n * (n - 1) / 2.
     *    - Count good pairs using a hash map `diffToCount` to track the frequency of `i - nums[i]`.
     * 3. Iterate through the array and:
     *    - Compute the difference `i - nums[i]`.
     *    - If the difference exists in the map, add its frequency to the count of good pairs.
     *    - Update the frequency of the current difference in the hash map.
     * 4. Calculate bad pairs as `totalPairs - goodPairs`.
     *
     * Complexity:
     * - Time Complexity: O(n), where `n` is the size of the input array. Each operation on the hash map is O(1) on average.
     * - Space Complexity: O(n), for storing the hash map.
     **/
    long long countBadPairs(vector<int>& nums) 
    {
        int n = nums.size();
        
        // Total number of pairs in the array
        long long badPairsCount = n * (n - 1LL) / 2;

        unordered_map<int, int> diffToCount; // Tracks frequency of i - nums[i].

        for (int i = 0; i < n; ++i) 
        {
            int diff = i - nums[i];
            
            // If this difference exists in the map, subtract its frequency from bad pairs
            if (diffToCount.count(diff))
                badPairsCount -= diffToCount[diff];

            ++diffToCount[diff];
        }

        return badPairsCount;
    }
};
