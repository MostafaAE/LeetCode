class Solution {
public:
    /*
     * Approach:
     * One-Pass Greedy
     * - Traverse the ratings array once, maintaining the length of increasing (`up`) and decreasing (`down`) sequences.
     * - A "peak" value is tracked to ensure that the peak element in a "mountain" gets enough candies.
     * - Reset the counters appropriately based on the current relationship between adjacent ratings.
     * 
     * Time Complexity : O(n) where n is the number of children
     * Space Complexity: O(1) extra space (constant)
     */
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        int up = 0, down = 0, peak = 0; // Counters for trend lengths
        int result = 1;

        for (int i = 1; i < n; ++i) 
        {
            if (ratings[i] < ratings[i - 1]) // Descending trend
            {
                up = 0; // Reset increasing sequence
                ++down;
                // Add descending candies + 1 if peak child needs more
                result += down + (down > peak);
            }
            else if (ratings[i] == ratings[i - 1]) // Flat
            {
                // Reset everything since no preference
                up = down = peak = 0;
                ++result; // One candy for current child
            }
            else // Ascending trend
            {
                down = 0; // Reset decreasing sequence
                ++up;
                peak = up; // Update peak height
                result += 1 + up; // Current child gets more than previous
            }
        }

        return result;
    }
};