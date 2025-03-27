class Solution {
public:
    /**
     * Approach:
     * 1. **Find the Dominant Number**: 
     *    - Use the **Boyer-Moore Voting Algorithm** to determine the dominant number, 
     *      which is the most frequent element appearing more than `n/2` times.
     * 
     * 2. **Count Total Occurrences of the Dominant Number**:
     *    - Traverse the array again to compute `totalDominantFreq`, the number of times the dominant number appears.
     *
     * 3. **Find the Minimum Valid Index**:
     *    - Iterate through the array while maintaining the `leftDominantFreq` count.
     *    - Compute `rightDominantFreq` dynamically.
     *    - If both `left` and `right` partitions are **valid** (each has the dominant number occurring > half their size),
     *      return the current index.
     *
     * Complexity Analysis:
     * - **Total Time Complexity**: **O(N)**.
     *      - **Finding the dominant number**: **O(N)**.
     *      - **Counting occurrences**: **O(N)**.
     *      - **Finding the valid split**: **O(N)**.
     * - **Space Complexity**: **O(1)** (constant extra space used).
     */
    int minimumIndex(vector<int>& nums) 
    {
        int n = nums.size(), dominantNum{}, dominantVote{};

        // Step 1: Find the dominant number using Boyer-Moore Voting Algorithm
        for (int i = 0; i < n; ++i) 
        {
            if (dominantVote == 0)
                dominantNum = nums[i];

            dominantVote += (nums[i] == dominantNum) ? 1 : -1;
        }

        // Step 2: Count the total occurrences of the dominant number
        int totalDominantFreq = count(nums.begin(), nums.end(), dominantNum);

        // Step 3: Find the minimum valid index
        int leftDominantFreq = 0;
        for (int i = 0; i < n - 1; ++i) 
        {
            if (nums[i] == dominantNum)
                ++leftDominantFreq;
            
            int rightDominantFreq = totalDominantFreq - leftDominantFreq;

            // Check if both left and right subarrays satisfy the condition
            if (leftDominantFreq * 2 > i + 1 && rightDominantFreq * 2 > n - i - 1)
                return i;
        }

        return -1; // No valid partition found
    }
};