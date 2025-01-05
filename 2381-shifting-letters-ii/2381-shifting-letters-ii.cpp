class Solution {
public:
    /**
     * Approach:
     * - Use a difference array to efficiently calculate the net shift for each character.
     * - For each shift operation:
     *     - Add or subtract 1 at the start and end+1 indices in the difference array, depending on the shift direction.
     * - Traverse the string while accumulating the total shift (`numOfShifts`) and apply it to each character:
     *     - Compute the new character index using modulo arithmetic to ensure it wraps within the range of alphabetic indices.
     *     - Adjust for negative shifts by adding 26 before taking modulo 26.
     * 
     * Complexity:
     * Time Complexity: O(n + m), where `n` is the length of the string and `m` is the number of shifts.
     * - Processing all shift operations: O(m).
     * - Applying the shifts to the string: O(n).
     * Space Complexity: O(n) for the difference array.
     */

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArray(n + 1, 0);

        // Build the difference array for shift directions
        for (auto& shift : shifts) {
            int direction = shift[2] ? 1 : -1;
            diffArray[shift[0]] += direction;
            diffArray[shift[1] + 1] -= direction;
        }

        // Apply the cumulative shifts to the string
        int numOfShifts = 0;
        string shifted(n, ' ');
        for (int i = 0; i < n; ++i) {
            numOfShifts += diffArray[i];
            int charIndex = s[i] - 'a';
            int shiftedCharIndex = ((charIndex + numOfShifts) % 26 + 26) % 26; // Ensure non-negative modulo
            shifted[i] = 'a' + shiftedCharIndex;
        }

        return shifted;
    }
};
