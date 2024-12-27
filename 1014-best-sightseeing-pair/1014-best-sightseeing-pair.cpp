class Solution {
public:
    /**
     * Approach:
     * - To maximize the score for a sightseeing pair `values[i] + values[j] + i - j` (where `i < j`):
     * - Iterate from the end of the array to the beginning.
     * - Maintain `maxFromSubtract = max(values[j] - j)` as you traverse.
     * - At each step, compute the potential score using `values[i-1] + (i-1) + maxFromSubtract`.
     * - Update the result if the computed score is greater than the current maximum.
     *
     * Time Complexity: O(n), where `n` is the size of the input array.
     * Space Complexity: O(1), since no additional space is used.
     */
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int n = values.size(), result{INT_MIN}, maxFromSubtract{INT_MIN};

        // Traverse the array in reverse
        for (int i = n - 1; i > 0; --i) 
        {
            // Update maxFromSubtract with the current `values[i] - i`
            maxFromSubtract = max(maxFromSubtract, values[i] - i);

            // Calculate the score for `values[i-1] + (i-1) + maxFromSubtract`
            result = max(result, values[i-1] + (i - 1) + maxFromSubtract);
        }

        return result;
    }
};
