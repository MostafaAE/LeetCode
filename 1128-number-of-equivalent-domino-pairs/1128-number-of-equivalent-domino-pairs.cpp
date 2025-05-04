/**
 * Approach:
 * - We are given pairs of dominoes and need to count how many pairs are *equivalent*.
 * - Two dominoes [a, b] and [c, d] are equivalent if (a == c and b == d) or (a == d and b == c),
 *   meaning the domino can be rotated.
 * 
 * Optimization Strategy:
 * - To avoid checking all pairs (O(n²)), we use a hash map to count occurrences of normalized domino keys.
 * - Normalize each domino by always storing the smaller value first: key = min(a, b) * 10 + max(a, b)
 *   (Using multiplication by 10 works because values are in [1, 9])
 * - For each domino key seen before, add the count to the result, since each previous occurrence forms a new pair.
 * 
 * Time Complexity: O(n)
 * - We loop over the `dominoes` array once.
 * 
 * Space Complexity: O(1)
 * - Although we use a hash map, the number of unique dominoes is limited (at most 100).
 */

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        unordered_map<int, int> count; // Map to track frequency of each normalized domino key
        int result = 0;

        for (auto& d : dominoes)
        {
            int x = d[0], y = d[1];

            // Normalize the key: ensure smaller value comes first to handle [a,b] == [b,a]
            int key = min(x, y) * 10 + max(x, y);

            // Add the number of previous identical dominoes to the result
            result += count[key];

            // Increment the count of this normalized domino
            count[key]++;
        }

        return result;
    }
};
