class Solution 
{
public:
    /**
     * Approach:
     * - We traverse the `colors` array while maintaining a **sliding window** of alternating colors.
     * - The window expands when the current color is different from the last color.
     * - If the window reaches size `k`, we count it as a valid alternating group and reduce the window size.
     * - The array is treated **circularly** by using modulo indexing.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n + k), since we iterate over `n + k - 1` elements at most.
     * - **Space Complexity**: O(1)
     */
    int numberOfAlternatingGroups(vector<int>& colors, int k) 
    {
        int n = colors.size(), windowSize{1}, result{};
        int lastColor = colors[0];

        for (int i = 1; i < n + k - 1; ++i) 
        {
            int curIdx = i % n; // Circular indexing

            // Expand window if the color alternates, else reset it
            if (colors[curIdx] != lastColor) 
            {
                ++windowSize;
            } 
            else 
            {
                windowSize = 1;
            }

            // If we reach the required window size, count the group and shrink window
            if (windowSize == k) 
            {
                ++result;
                --windowSize; // Maintain overlap for next group
            }

            lastColor = colors[curIdx];
        }

        return result;
    }
};
