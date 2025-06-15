class Solution {
public:
    /*
     * Approach:
     * - Convert the number to a string for digit-wise manipulation.
     * - For the maximum value:
     *   - Replace the first digit (not already '9') with '9'.
     * - For the minimum value:
     *   - If the first digit is not '1', replace it with '1' (to avoid leading zero).
     *   - Otherwise, find the first digit (not '1') and replace it with '0'.
     * - Compute and return the difference.
     * 
     * Helper Function:
     * - replaceFirstDigitWith(val, str, exclude):
     *   - Replaces all occurrences of the first eligible digit (≠ exclude, ≠ val) with `val`.
     *
     * Time Complexity : O(d), where d is the number of digits in `num` (up to 9).
     * Space Complexity: O(d) for temporary string manipulation.
     */
    int maxDiff(int num) 
    {
        string str = to_string(num);

        // Max: Replace first eligible digit with '9'
        int maxVal = replaceFirstDigitWith('9', str);

        // Min: Replace first eligible digit with '1' or '0' based on leading digit
        int minVal = str[0] != '1' ? replaceFirstDigitWith('1', str) : replaceFirstDigitWith('0', str, '1');
        
        return maxVal - minVal;
    }

private:
    int replaceFirstDigitWith(char val, string str, char exclude = 'x')
    {
        char toReplace = 'x'; // Placeholder for the digit to be replaced

        for (int i = 0; i < str.size(); ++i)
        {
            // Identify the first digit that is not already `val` or the digit to exclude
            if (toReplace == 'x' && str[i] != exclude && str[i] != val)
            {
                toReplace = str[i];
            }

            // Replace all occurrences of the target digit
            if (str[i] == toReplace)
            {
                str[i] = val;
            }
        }

        return stoi(str);
    }
};
