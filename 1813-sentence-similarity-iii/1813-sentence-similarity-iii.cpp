class Solution {
public:
    /**
     * Approach:
     * - Convert both sentences into vectors of words.
     * - If `s1` has more words than `s2`, swap them to always compare the smaller sentence with the larger one.
     * - Use two pointers, `start` and `end`, to check for matching words from the beginning and the end of the sentences.
     * - Continue moving `start` from the beginning as long as the words match, and `end` from the end as long as the words match.
     * - After both passes, if all words in `s1` can fit as a subsequence in `s2`, return true, otherwise return false.
     * 
     * Complexity:
     * - Time Complexity: O(n + m), where `n` is the total number of words in s1 and `m` is the number of words in s2.
     * - Space Complexity: O(n + m), for storing the words of both sentences in vectors.
     */
    bool areSentencesSimilar(string s1, string s2) 
    {
        // Convert sentences to lists of words
        stringstream ss1(s1), ss2(s2);
        string word;
        vector<string> s1Words, s2Words;
        
        while (ss1 >> word) 
            s1Words.push_back(word);
        while (ss2 >> word) 
            s2Words.push_back(word);

        // If words in s1 are more than s2, swap them.
        if (s1Words.size() > s2Words.size())
            swap(s1Words, s2Words);

        int start = 0, ends1 = s1Words.size() - 1, ends2 = s2Words.size() - 1;
        
        // Find the maximum words matching from the beginning.
        while (start < s1Words.size() && s1Words[start] == s2Words[start])
            ++start;

        // Find the maximum words matching in the end.
        while (ends1 >= 0 && s1Words[ends1] == s2Words[ends2]) 
        {
            --ends1;
            --ends2;
        }

        // If ends1 index is less than start, then sentence is similar.
        return ends1 < start;
    }
};