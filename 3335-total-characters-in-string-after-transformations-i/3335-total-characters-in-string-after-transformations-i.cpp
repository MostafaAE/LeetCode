class Solution {
public:
    /*
     * Approach:
     * - Use a frequency array for each character ('a' to 'z').
     * - Each transformation simulates a character shift:
     *   * All characters move one step forward.
     *   * 'z' becomes both 'a' and 'b' (its count splits).
     * - Simulate this process `t` times and sum the final frequencies.
     *
     * Time Complexity: O(N + 26 * T) ≈ O(N + T)
     * Space Complexity: O(1) (constant space for 26 letters)
     */
    int lengthAfterTransformations(string s, int t) 
    {
        const int MOD = 1e9 + 7;
        vector<int> charFreq(26, 0);

        // Count initial character frequencies
        for (char c : s)
            charFreq[c - 'a']++;

        // Simulate T transformations
        for (int step = 0; step < t; ++step)
        {
            int zCount = charFreq[25];  // Save count of 'z'

            // Shift all characters forward by one
            for (int i = 25; i >= 1; --i)
                charFreq[i] = charFreq[i - 1];

            charFreq[0] = zCount;  // 'z' turns into 'a'
            charFreq[1] = (charFreq[1] + zCount) % MOD;  // 'z' also adds to 'b'
        }

        // Sum all character frequencies modulo MOD
        int result = 0;
        for (int freq : charFreq)
            result = (result + freq) % MOD;

        return result;
    }
};