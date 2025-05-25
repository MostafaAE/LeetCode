class Solution {
public:
    /*
     * Approach:
     * Hash Map + Greedy Pairing
     * 
     * - We try to greedily pair each word with its reverse to form palindromes.
     * - Each pair (e.g., "ab" + "ba") contributes 4 characters to the final palindrome.
     * - If a word cannot find its reverse yet, we store it in a hash map.
     * - For words with identical characters (e.g., "aa"), we can place *one* in the center
     *   if unpaired (adds 2 to the length).
     *
     * Time Complexity: O(N)
     * - N is the number of words; each word and its reverse are processed once.
     * 
     * Space Complexity: O(N)
     * - We use a hash map to store up to N unpaired words.
     */
    int longestPalindrome(vector<string>& words) 
    {
        int length{};
        unordered_map<string, int> wordToCount;

        // First pass: try to pair each word with its reverse
        for(string word : words)
        {
            string revWord = word;
            swap(revWord[0], revWord[1]);

            // Check if the reverse word is available to pair
            if(wordToCount[revWord] > 0)
            {
                --wordToCount[revWord];
                length += 4;
            }
            else
            {
                ++wordToCount[word];
            }
        }

        // Second pass: look for a symmetric word (like "aa", "cc") to put in the center
        for(auto& [word, count] : wordToCount)
        {
            if(count > 0 && word[0] == word[1])  // can be placed in the middle
            {
                length += 2;
                break;
            }
        }

        return length;
    }
};