class Solution {
public:
    // Approach:
    // 1. Use two hash maps, one to track the frequency of each color, and the other to map indices to their assigned colors.
    // 2. For each query:
    //    - Increment the frequency of the new color in `colorFrequency`.
    //    - If the index already has a color, decrement the frequency of the old color.
    //    - Remove the old color from `colorFrequency` if its frequency becomes 0.
    //    - Update the mapping of the index to the new color.
    // 3. Store the size of `colorFrequency` (the count of unique colors) in the result array.
    // 4. Return the result array after processing all queries.

    // Complexity:
    // - Time Complexity: O(n), where n is the number of queries. Each operation on `unordered_map` is O(1) on average.
    // - Space Complexity: O(n)

    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        unordered_map<int, int> colorFrequency; // Tracks the frequency of each color.
        unordered_map<int, int> idxToColor;    // Maps each index to its assigned color.

        int queriesCount = queries.size();
        vector<int> result(queriesCount, 0);

        for (int i = 0; i < queriesCount; ++i) 
        {
            int idx = queries[i][0];
            int color = queries[i][1];

            // Increment the frequency of the new color.
            ++colorFrequency[color];

            // If the index already has a color, decrement its frequency.
            if (idxToColor.count(idx)) 
            {
                int oldColor = idxToColor[idx];
                --colorFrequency[oldColor];

                if (colorFrequency[oldColor] == 0)
                    colorFrequency.erase(oldColor);
            }

            // Update the index-to-color mapping with the new color.
            idxToColor[idx] = color;

            result[i] = colorFrequency.size();
        }

        return result;
    }
};
