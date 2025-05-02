/**
 * Approach:
 * - The problem simulates domino pushes where each domino can be pushed to the left ('L') or right ('R'), or remain upright ('.').
 * - We'll convert the string into intervals between non-dot dominoes, simulating the force in those regions:
 *   1. If two same forces (e.g., 'R'...'R' or 'L'...'L') appear, all dominos in between follow the same force.
 *   2. If opposite forces (e.g., 'R'...'L') appear, the dominos between them fall inward towards each other.
 *   3. If forces are 'L'...'R', nothing changes between them, as they don't influence each other.
 * - We add sentinel dominoes at the start and end: -1 with 'L' and n with 'R' to handle edge cases cleanly.
 * 
 * Time Complexity: O(n)
 * - We make a single pass through the string and through each segment between non-dot dominos.
 * 
 * Space Complexity: O(n)
 * - We store index-symbol pairs for the non-dot characters.
 */

class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        int n = dominoes.size();
        vector<pair<int, char>> indexToChar;

        // Add a sentinel domino pushed to the left at index -1
        indexToChar.emplace_back(-1, 'L');

        // Collect positions of non-dot dominoes
        for (int i = 0; i < n; ++i)
        {
            if (dominoes[i] != '.')
            {
                indexToChar.emplace_back(i, dominoes[i]);
            }
        }

        // Add a sentinel domino pushed to the right at index n
        indexToChar.emplace_back(n, 'R');

        string result = dominoes;
        int len = indexToChar.size();

        // Iterate over each segment between non-dot dominos
        for (int i = 0; i < len - 1; ++i)
        {
            int leftIdx = indexToChar[i].first;
            int rightIdx = indexToChar[i + 1].first;
            char leftSymbol = indexToChar[i].second;
            char rightSymbol = indexToChar[i + 1].second;

            if (leftSymbol == rightSymbol)
            {
                // Case: same forces (R...R or L...L) → fill in the same force
                for (int idx = leftIdx + 1; idx < rightIdx; ++idx)
                {
                    result[idx] = leftSymbol;
                }
            }
            else if (leftSymbol == 'R' && rightSymbol == 'L')
            {
                // Case: opposing forces (R...L) → fill inwards from both sides
                int l = leftIdx + 1;
                int r = rightIdx - 1;
                while (l < r)
                {
                    result[l++] = 'R';
                    result[r--] = 'L';
                }
                // Middle domino (if any) remains '.' when l == r
            }
            // Case: L...R → do nothing, dominos stay upright ('.')
        }

        return result;
    }
};