/*
 * Approach:
 * - Greedy
 * - Track current position on the 2D plane:
 *      * latitude  = (N - S)
 *      * longitude = (E - W)
 * - At each step, compute the Manhattan distance:
 *      abs(latitude) + abs(longitude)
 * - You are allowed to flip up to k characters so the distance can be increased by at most 2 * k.
 * - The result cannot exceed the number of characters seen so far (i + 1).
 * - At each step, update the maximum result.
 *
 * Time Complexity: O(n), where n = size of string s
 * Space Complexity: O(1)
 */

class Solution {
public:
    int maxDistance(string s, int k) 
    {
        int latitude = 0, longitude = 0;
        int n = s.size(), result = 0;

        for (int i = 0; i < n; ++i) 
        {
            // Update position based on move
            switch (s[i]) 
            {
                case 'N': latitude++; break;
                case 'S': latitude--; break;
                case 'E': longitude++; break;
                case 'W': longitude--; break;
            }

            // Calculate potential max distance after flipping up to k moves
            int maxDistance = min(abs(latitude) + abs(longitude) + k * 2, i + 1);

            result = max(result, maxDistance);
        }

        return result;
    }
};