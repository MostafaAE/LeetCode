/*
 * Approach:
 * - Use a greedy strategy:
 *   - Maintain counts of moves in each of the four directions (N, S, E, W).
 *   - For each new move, update the direction count.
 *   - After each move, calculate the current possible maximum distance by:
 *       * Flipping up to `k` moves from opposite directions to increase distance.
 *       * Vertical axis: (N - S), Horizontal axis: (E - W)
 *       * Use k optimally to maximize vertical and horizontal distances.
 *
 * Time Complexity: O(n), where n = size of string s
 * Space Complexity: O(1)
 */

class Solution {
public:
    int maxDistance(string s, int k) 
    {
        unordered_map<char, int> charToIdx {{'N', 0}, {'S', 1}, {'E', 2}, {'W', 3}};
        vector<int> charToCount(4, 0);
        int maxDistance = 0;

        for (char c : s)
        {
            ++charToCount[charToIdx[c]];
            maxDistance = max(maxDistance, calculateMaxDistance(charToCount, k));
        }

        return maxDistance;
    }

private:
    int calculateMaxDistance(vector<int> charToCount, int k)
    {
        int nCount = charToCount[0], sCount = charToCount[1];
        int eCount = charToCount[2], wCount = charToCount[3];

        int maxVertical = max(nCount, sCount), minVertical = min(nCount, sCount);
        int maxHorizontal = max(eCount, wCount), minHorizontal = min(eCount, wCount);

        // Flip vertically as much as possible
        int possibleToFlipVertically = min(minVertical, k);
        
        k -= possibleToFlipVertically;

        // Then flip horizontally with remaining k
        int possibleToFlipHorizontally = min(minHorizontal, k);

        // Total distance after optimal flips
        return (maxVertical - minVertical + 2 * possibleToFlipVertically) + 
               (maxHorizontal - minHorizontal + 2 * possibleToFlipHorizontally);
    }
};