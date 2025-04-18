/**
 * Approach:
 * - This is a recursive problem where:
 *     countAndSay(1) = "1"
 *     countAndSay(n) = say what you "see" in countAndSay(n - 1)
 * 
 * - For each recursive step:
 *     - Get the string for countAndSay(n - 1).
 *     - Use Run-Length Encoding (RLE) to describe it.
 *     - For example, "1211" => one 1, one 2, two 1s => "111221".
 * 
 * - The helper `convertToRLE` encodes a string using RLE logic.
 * 
 * Time Complexity:
 * - Let L be the length of the resulting string at step n.
 * - Total time is roughly O(L) for each step, and there are n steps.
 * - In worst case, time complexity is O(2^n) due to string length doubling in some cases.
 * 
 * Space Complexity:
 * - O(L) for storing the intermediate string representations.
 */

class Solution {
public:
    /**
     * Main function to compute the nth term in the count-and-say sequence.
     */
    string countAndSay(int n) 
    {
        if (n == 1)
            return "1";

        string str = countAndSay(n - 1);        // Recursive call to get previous term
        string rle = convertToRLE(str);         // Convert it to RLE format
        return rle;
    }

    /**
     * Helper function to convert a string to its run-length encoding.
     * E.g. "221" -> "221" => "two 2s, one 1" => "221"
     */
    string convertToRLE(string str)
    {
        int n = str.size();
        vector<pair<char, int>> charToCount;

        // Initialize with the first character
        charToCount.emplace_back(str[0], 1);

        // Count consecutive characters
        for (int i = 1; i < n; ++i)
        {
            if (str[i] == str[i - 1])
            {
                charToCount.back().second++;
            }
            else
            {
                charToCount.emplace_back(str[i], 1);
            }
        }

        // Build the RLE result string
        string rle{};
        for (auto& p : charToCount)
        {
            rle += to_string(p.second);  // Count
            rle += p.first;              // Character
        }

        return rle;
    }
};
