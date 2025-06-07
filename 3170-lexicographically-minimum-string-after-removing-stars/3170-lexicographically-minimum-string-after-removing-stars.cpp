class Solution {
public:
    /*
     * Approach:
     * Greedy with Character Index Tracking
     * - Traverse the string and keep track of each character's indices in a list grouped by character.
     * - On encountering '*', remove the most recent occurrence of the lexicographically smallest character.
     * - At the end, build a result string by skipping all '*' characters.
     *
     * Time Complexity : O(n * 26) = O(n), where n is the length of the string.
     *   - Each '*' requires scanning at most 26 entries to find the smallest character.
     *   - Overall linear since each character is visited and removed once.
     *
     * Space Complexity: O(n) for storing character indices (worst case when all are non-*).
     */
    string clearStars(string s) 
    {
        int n = s.size();
        vector<vector<int>> charToIdx(26); // Stores positions for each character

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '*')
            {
                removeSmallestCharacter(s, charToIdx);
            }
            else
            {
                charToIdx[s[i] - 'a'].push_back(i);
            }
        }

        string result;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != '*')
            {
                result += s[i];
            }
        }

        return result;
    }

private:
    // Removes the most recent occurrence of the smallest lexicographical character
    void removeSmallestCharacter(string& s, vector<vector<int>>& charToIdx)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (!charToIdx[i].empty())
            {
                int idx = charToIdx[i].back();
                s[idx] = '*'; // Mark it for removal
                charToIdx[i].pop_back(); // Remove the index from the tracking list
                break;
            }
        }
    }
};