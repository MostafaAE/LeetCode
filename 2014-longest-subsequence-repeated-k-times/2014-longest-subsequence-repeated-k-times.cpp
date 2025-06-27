/*
 * Approach:
 * - We are to find the **longest subsequence `t`** such that `t` repeated `k` times is a subsequence of the original string `s`.
 * - First, we count character frequencies. Any character that appears less than `k` times can’t be part of the final answer.
 * - Using BFS, we generate all combinations of candidate strings (from most frequent characters) in **lexicographically decreasing order**.
 * - For each candidate, we check if it appears **k times as a subsequence** of `s`.
 * - If it does, we try to extend it by adding one of the valid characters to the end.
 * - The longest valid string we find this way is the result.
 */

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) 
    {
        // Step 1: Count character frequencies
        vector<int> freq(26, 0);
        for (char c : s)
        {
            ++freq[c - 'a'];
        }

        // Step 2: Filter candidates — characters that appear at least k times
        vector<char> candidates;
        for (int i = 25; i >= 0; --i) // Start from 'z' to get lexicographically largest
        {
            if (freq[i] >= k)
                candidates.push_back(i + 'a');
        }

        // Step 3: BFS to build and test possible subsequences
        queue<string> q;

        // Initialize the queue with 1-letter candidate strings
        for (char c : candidates)
            q.push(string(1, c));

        string result = "";

        // BFS to try appending valid characters
        while (!q.empty())
        {
            string cur = q.front();
            q.pop();

            // If current string is longer, update the result
            if (cur.size() > result.size())
                result = cur;

            // Try extending current string with each candidate character
            for (char c : candidates)
            {
                string next = cur + c;
                if (isRepeatedKTimes(s, next, k))
                {
                    q.push(next);
                }
            }
        }

        return result;
    }

private:
    // Helper: Checks whether `t` appears k times as a subsequence in `s`
    bool isRepeatedKTimes(const string& s, const string& t, int k)
    {
        int idx = 0;
        int count = 0;   // number of times t has been matched

        for (char c : s)
        {
            if (t[idx] == c)
            {
                ++idx;
                if (idx == (int)t.size())
                {
                    ++count;
                    idx = 0;
                    if (count == k)
                        return true;
                }
            }
        }

        return false;
    }
};