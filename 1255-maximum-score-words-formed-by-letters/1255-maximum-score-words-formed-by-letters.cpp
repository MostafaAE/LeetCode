class Solution {
public:
    /*
    * Approach:
    * - Use backtracking to explore all possible combinations of words.
    * - For each combination, check if the word can be formed using the available letters.
    * - Calculate the score of each valid combination and keep track of the maximum score.
    *
    * Complexity:
    * - Time Complexity: O(2^N * L), where N is the number of words and L is the average length of a word.
    *   This is because we explore all possible combinations of words (2^N) and for each combination, we 
    *   might check each letter in the words (L).
    * - Space Complexity: O(N), where N is the number of words (due to recursion depth)
    */
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        int maxScore{};
        
        unordered_map<char, int> letterToCount;
        for(auto c : letters)
            ++letterToCount[c];
        
        getMaxScore(0, words, letterToCount, score, 0, maxScore);
        
        return maxScore;
    }
    
    void getMaxScore(int idx, vector<string>& words, unordered_map<char, int>& letterToCount,
                    vector<int>& score, int curScore, int& maxScore)
    {
        if(idx >= words.size())
        {
            maxScore = max(maxScore, curScore);
            return;
        }
        
        // We have 2 choices
        
        // 1. Pick the current word
        if(canPickWord(idx, words, letterToCount))
        {
            int wordScore{};
            for(auto c : words[idx])
            {
                --letterToCount[c];
                wordScore += score[c - 'a'];
            }
            
            getMaxScore(idx + 1, words, letterToCount, score, curScore + wordScore, maxScore);
            
            for(auto c : words[idx])
                letterToCount[c]++;
        }
        
        // 2. Leave the current word
        getMaxScore(idx + 1, words, letterToCount, score, curScore, maxScore);
    }
    
    // Helper function to check if we have suffecient letters to pick this word
    bool canPickWord(int idx, vector<string>& words, unordered_map<char, int>& letterToCount)
    {
        unordered_map<char, int> wordLetterToCount;
        for(auto c : words[idx])
            ++wordLetterToCount[c];
        
        for(auto [ch, count] : wordLetterToCount)
            if(letterToCount[ch] < count)
                return false;
        
        return true;
    }
};