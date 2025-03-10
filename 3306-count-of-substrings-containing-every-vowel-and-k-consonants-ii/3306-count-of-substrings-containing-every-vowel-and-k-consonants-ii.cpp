class Solution 
{
public:
    /**
     * Approach:
     * - We use a **two-pointer sliding window** approach to count substrings that contain **all 5 vowels** at least once and **exactly k consonants**.
     * - To count **exactly k consonants**, we calculate `atLeastK(k) - atLeastK(k + 1)`, where:
     *   - `atLeastK(k)`: Number of substrings with at least `k` consonants.
     *   - `atLeastK(k + 1)`: Number of substrings with at least `k + 1` consonants.
     * - The helper function `atLeastK()`:
     *   - Expands the window (`right` pointer) while adding vowels to a frequency map.
     *   - Shrinks the window (`left` pointer) if consonant count exceeds `k`.
     *   - Adds `n - right` substrings to the result whenever the window is valid.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n), as each character is processed at most twice (once when expanding, once when shrinking).
     * - **Space Complexity**: O(1), as we use a fixed hash map (at most 5 vowels) and a few integer variables.
     */
    long long countOfSubstrings(string word, int k) 
    {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }

private:
    /**
     * Counts substrings with at least `k` consonants and all 5 vowels.
     */
    long long atLeastK(string word, int k)
    {
        unordered_map<char, int> vowelToCount;
        long long result{};
        int consonantsCount{}, n = word.size(), left{}, right{};

        while (right < n) 
        {
            // Expand window by adding the rightmost character
            isVowel(word[right]) ? vowelToCount[word[right]]++ : consonantsCount++;

            // Shrink window if consonant count is too high
            while (consonantsCount >= k && vowelToCount.size() == 5) 
            {
                result += n - right; // All substrings starting from 'left' to 'n-1' are valid

                char startLetter = word[left];
                bool isCharVowel = isVowel(startLetter);
                consonantsCount -= !isCharVowel; // Decrease consonant count if left character is a consonant

                // Remove vowel from map if its count becomes zero
                if (isCharVowel && --vowelToCount[startLetter] == 0)
                    vowelToCount.erase(startLetter);
                
                ++left;
            }

            ++right;
        }

        return result;
    }

    /**
     * Helper function to check if a character is a vowel.
     */
    bool isVowel(char c) 
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
