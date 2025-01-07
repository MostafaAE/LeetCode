class Solution {
public:
    /**
     * Approach:
     * - Iterate through each word in the input list.
     * - For each word, check if it is a substring of any other word in the list using the `find` function which utilizes KMP algorithm.
     * - If it is found as a substring, add it to the result list.
     * 
     * Complexity:
     * Time Complexity: O(n^2 * m), where:
     * - `n` is the number of words.
     * - `m` is the average length of the words.
     * - Checking if one string is a substring of another takes O(m), and we do this for all pairs.
     * Space Complexity: O(1), excluding the result vector.
     */
    vector<string> stringMatching(vector<string>& words) 
    {
        int n = words.size();
        vector<string> result;

        // Iterate through each word
        for (int i = 0; i < n; ++i) 
        {
            bool isFound = false;

            // Check against every other word
            for (int j = 0; j < n; ++j) 
            {
                if (i == j) continue; // Skip comparing the word with itself
                
                // Check if words[i] is a substring of words[j]
                if (words[j].find(words[i]) != string::npos) 
                {
                    isFound = true;
                    break;
                }
            }

            // Add the word to the result if it is found as a substring
            if (isFound)
                result.push_back(words[i]);
        }

        return result;
    }
};