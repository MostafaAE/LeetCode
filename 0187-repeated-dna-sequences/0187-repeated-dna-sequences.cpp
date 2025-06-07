class Solution {
public:
    /*
     * Approach:
     * Hashing (Sliding Window + HashSet)
     * - Use a fixed-length window of size 10 (sequence length).
     * - For each window, extract the substring and check if it's already seen.
     * - If it is seen before, insert it into a "repeated" set to avoid duplicates in the result.
     *
     * Time Complexity : O(n), where n is the length of the input string.
     *   - Each substring extraction is O(1) amortized since substrings are of fixed size.
     *   - HashSet operations (insert and lookup) are O(1) on average.
     *
     * Space Complexity: O(n), for storing all seen and repeated substrings.
     */
    vector<string> findRepeatedDnaSequences(string s) 
    {
        int sequenceLength = 10;
        int n = s.size();

        if (n <= sequenceLength)
            return {};

        unordered_set<string> seen;
        unordered_set<string> repeated;

        for (int i = 0; i <= n - sequenceLength; ++i)
        {
            string seq = s.substr(i, sequenceLength);
            if (seen.count(seq))
            {
                repeated.insert(seq);
            }
            else
            {
                seen.insert(seq);
            }
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};