class Solution {
private:
    static const int MAX = 101;
    int memory[MAX];
    string str;
public:
    /*
     * Approach:
     * - Use top-down dynamic programming with memoization.
     * - For each index, recursively explore:
     *     * One-digit decoding (if not '0').
     *     * Two-digit decoding (if valid, i.e., "10" to "26").
     * - Cache intermediate results to avoid recomputation.
     *
     * Time Complexity: O(N), where N is the length of the input string.
     * Space Complexity: O(N) for memoization.
     */
    int numDecodings(string s) 
    {
        memset(memory, -1, sizeof(memory));
        str = s;
        return decodeWays(0);
    }

    // Recursive function to count decoding ways starting from index `idx`
    int decodeWays(int idx) 
    {
        if (idx >= (int)str.size())
            return 1;  // Reached end, valid decoding path

        if (str[idx] == '0')
            return 0;  // '0' can't be decoded alone

        int& ret = memory[idx];
        if (ret != -1)
            return ret;

        // Decode one digit
        ret = decodeWays(idx + 1);

        // Decode two digits if valid (10–26)
        if (idx < (int)str.size() - 1 && (str[idx] == '1' || (str[idx] == '2' && str[idx + 1] <= '6')))
            ret += decodeWays(idx + 2);

        return ret;
    }
};