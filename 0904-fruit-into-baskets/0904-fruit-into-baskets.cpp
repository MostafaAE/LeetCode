/*
 * Goal: Find the length of the longest subarray that contains at most 2 different fruit types.
 *
 * Approach:
 * - Use a sliding window [left, right].
 * - Use a hash map to track the count of each fruit type in the window.
 * - If the window contains more than 2 types, move the left pointer to shrink the window 
 *   and maintain at most 2 types.
 * - Track the maximum window size encountered during the traversal.
 *
 * Time Complexity: O(n)
 *   - Each element is visited at most twice (once added, once removed).
 *
 * Space Complexity: O(1)
 *   - The map stores at most 3 fruit types at any time, so space is constant.
 */

class Solution 
{
public:
    int totalFruit(vector<int>& fruits) 
    {
        unordered_map<int, int> typeToCount;
        int n = fruits.size(), totalFruits = 0, left = 0;

        for (int right = 0; right < n; ++right)
        {
            // Add the current fruit to the window
            ++typeToCount[fruits[right]];

            // If we have more than 2 types, shrink the window from the left
            while (typeToCount.size() > 2)
            {
                int fruitType = fruits[left];
                --typeToCount[fruitType];

                // Remove the fruit type from the map if its count becomes zero
                if (typeToCount[fruitType] == 0)
                    typeToCount.erase(fruitType);

                ++left;
            }

            // Update the maximum number of fruits collected
            totalFruits = max(totalFruits, right - left + 1);
        }

        return totalFruits;
    }
};