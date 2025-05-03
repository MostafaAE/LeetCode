/**
 * Approach:
 * - We are given two arrays representing the top and bottom halves of dominoes.
 * - Our goal is to determine the minimum number of rotations (swaps) needed to make all values in either `tops` or `bottoms` the same.
 * 
 * Key Insight:
 * - For the final value to be uniform across all dominos, the target value must appear in *every* domino (either on the top or bottom).
 * - We only need to check at most **two possible target values**: `tops[0]` and `bottoms[0]`.
 *   Why? Because if any solution exists, it must use one of these values.
 * 
 * Strategy:
 * 1. Try using `tops[0]` as the target:
 *    - For each domino:
 *        - If neither top nor bottom has the target → not possible.
 *        - Otherwise, count how many rotations are needed to move target to the top or to the bottom.
 * 2. If that fails, try using `bottoms[0]` as the target.
 * 3. Return the minimum number of rotations required for a valid configuration.
 * 
 * Time Complexity: O(n)
 * - We iterate through the arrays once or twice depending on the first check.
 * 
 * Space Complexity: O(1)
 * - Only constant extra space is used.
 */

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        // First try using the top of the first domino as the target
        int rotations = check(tops[0], tops, bottoms);
        if (rotations != -1) 
            return rotations;

        // Try the bottom of the first domino (only if different from tops[0])
        return check(bottoms[0], tops, bottoms);
    }

private:
    int check(int target, const vector<int>& tops, const vector<int>& bottoms) 
    {
        int topRotations = 0;
        int bottomRotations = 0;
        int n = tops.size();

        for (int i = 0; i < n; ++i) 
        {
            // If the current domino cannot have the target on either side → impossible
            if (tops[i] != target && bottoms[i] != target) 
                return -1;

            // If top doesn't already have the target, we'll need to rotate it
            if (tops[i] != target) 
                ++topRotations;

            // If bottom doesn't already have the target, we can consider rotating the other way
            if (bottoms[i] != target) 
                ++bottomRotations;
        }

        // Return the minimal rotations needed to make all values equal to target
        return min(topRotations, bottomRotations);
    }
};