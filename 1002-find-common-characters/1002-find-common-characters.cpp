class Solution {
public:
    /*
    * Approach:
    * - Initialize a frequency map for the first word.
    * - Traverse each subsequent word, updating the frequency map to retain the minimum frequency of each character (common).
    * - Construct the result based on the minimum frequencies of each character.
    *
    * Complexity:
    * - Time Complexity: O(n * m), where n is the number of words and m is the average length of a word.
    * - Space Complexity: O(1), since we only use a fixed amount of extra space (26 letters in frequency maps).
    */
    vector<string> commonChars(vector<string>& words) 
    {
        unordered_map<char, int> charToCount;
        vector<string> result;
        
        for(auto c : words[0])
            charToCount[c]++;
        
        for(int i = 1 ; i < words.size(); ++i)
        {
            unordered_map<char, int> curCharToCount;
            for(auto c : words[i])
                curCharToCount[c]++;
            
            // get the intersection of the two words
            for(auto [c, count] : charToCount)
                charToCount[c] = min(count, curCharToCount[c]);
        }
        
        // construct the result
        for(auto [c, count] : charToCount)
        {
            for(int i = 0 ; i < count ; ++i)
            {
                string s{c};
                result.push_back(s);
            }
        }
        
        return result;
    }
};