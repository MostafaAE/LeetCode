class Solution {
public:
    /*
     * Approach:
     * - To find the minimum and maximum values obtainable by replacing **one digit** across the number:
     *   - Replace all occurrences of the **first digit that is not already '9'** with '9' → gives the maximum number.
     *   - Replace all occurrences of the **first digit that is not already '0'** with '0' → gives the minimum number.
     * - The difference between the max and min is the answer.
     *
     * Time Complexity : O(d), where d is the number of digits in `num` (at most 9).
     * Space Complexity: O(d) for string conversion and manipulation.
     */
    int minMaxDifference(int num) 
    {
        return replaceFirstDigitWith('9', num) - replaceFirstDigitWith('0', num);
    }

private:
    int replaceFirstDigitWith(char val, int num)
    {
        string str = to_string(num);
        char toReplace = 'x'; // Placeholder to determine which digit to replace

        for (int i = 0; i < str.size(); ++i)
        {
            // Identify the first digit that is not already `val`
            if (toReplace == 'x' && str[i] != val)
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