/*
 * Approach:
 * - Convert the input to `unsigned int` so that negative numbers are correctly treated as 2's complement 32-bit values.
 * - Use modulus operation to extract each hex digit (val % 16) from the least significant digit.
 * - Append corresponding character: '0' to '9' for 0–9, 'a' to 'f' for 10–15.
 * - Continue dividing by 16 until value becomes 0.
 * - Reverse the result string since we construct it from LSB to MSB.
 *
 * Time Complexity: O(1)
 * - Since the number is a 32-bit integer, the loop runs at most 8 times (32 bits / 4 bits per hex digit).
 *
 * Space Complexity: O(1)
 */

class Solution {
public:
    string toHex(int num) 
    {
        // Cast to unsigned to handle negative values correctly as 2's complement
        unsigned int val = num;
        
        if (val == 0)
            return "0";

        string result = "";

        while (val > 0)
        {
            int cur = val % 16;

            // Convert 0-9 to '0'-'9', 10-15 to 'a'-'f'
            if (cur > 9)
                result += 'a' + (cur - 10);
            else
                result += '0' + cur;

            val /= 16;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};