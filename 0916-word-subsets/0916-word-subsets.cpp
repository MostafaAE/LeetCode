class Solution {
public:
    /**
     * Approach:
     * - Compute the maximum frequency of each character across all words in `words2`.
     * - For each word in `words1`, count the frequency of each character and check if it satisfies 
     *   the universal condition:
     *     - For each character `ch` in `words2`, its frequency in the current word must be 
     *       greater than or equal to the maximum frequency required.
     *
     * Complexity:
     * Time Complexity: O((m + n) * l), where:
     * - `m` is the total number of characters across all words in `words2`.
     * - `n` is the total number of characters across all words in `words1`.
     * - `l` is the average word length
     * Space Complexity: O(1) (constant space for character frequencies, since we only use 26 lowercase letters).
     */
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        // Calculate the maximum frequency for each character across all words in words2
        unordered_map<char, int> maxFrequency;
        for (const string& word : words2) 
        {
            unordered_map<char, int> tempFrequency;
            for (char c : word)
                ++tempFrequency[c];
            
            for (auto& [ch, freq] : tempFrequency)
                maxFrequency[ch] = max(maxFrequency[ch], freq);
        }

        vector<string> result;

        // Check each word in words1
        for (const string& word : words1) 
        {
            unordered_map<char, int> wordFrequency;
            for (char c : word)
                ++wordFrequency[c];

            bool isUniversal = true;
            // Verify if the word is universal
            for (auto& [ch, freq] : maxFrequency) 
            {
                if (wordFrequency[ch] < freq) 
                {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal)
                result.push_back(word);
        }

        return result;
    }
};
