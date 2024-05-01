class Solution {
public:
    /*
    * Approach:
    * - Find the index of the given character 'ch'.
    * - If 'ch' is found, use the two pointers technique to reverse the prefix of the word up to the index of 'ch'.
    *
    * Complexity:
    * - Time Complexity: O(n)
    * - Space Complexity: O(1)
    */
    string reversePrefix(string word, char ch) 
    {
        int endIdx{-1};
        
        // Find the index of ch
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(word[i] == ch)
            {
                endIdx = i;
                break;
            }
        }
        
        // Use two pointers technique to reverse the prefix of the word
        for(int startIdx = 0 ; startIdx < endIdx; ++startIdx, --endIdx)
            swap(word[startIdx], word[endIdx]);
        
        return word;
    }
};