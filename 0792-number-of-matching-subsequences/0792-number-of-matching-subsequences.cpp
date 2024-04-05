class Solution {
public:
    /* 
    * Approach:
    * - Utilize a hashmap to map each char in `s` with its indicies.
    * - For each word in `words`, iterate over every character and check if it exists in `s` with an index greater than the last character index using binary search, and keep track of its index in `s`.
    * - If we reached the end of the word, then it's a matching subsequence, if we didn't find any char then it does not match.
    * 
    * Complexity:
    * Time Complexity : O(LNlog(M))
    * Space Complexity : O(M) => where L is the length of max word in words, N is the lenghth of words, M is the length of s
    */
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        unordered_map<char, vector<int>> charToIndicies;
        int count{};
        
        // O(M)
        for(int i = 0 ; i < (int)s.size() ; i++)
            charToIndicies[s[i]].push_back(i);
        
        // O(N)
        for(string word : words)
        {
            int lastCharIndex{-1};
            // O(L.log(M))
            for(int idx = 0 ; idx < word.size() ; idx++)
            {
                auto itr = upper_bound(charToIndicies[word[idx]].begin(), charToIndicies[word[idx]].end(), lastCharIndex);
                if(itr != charToIndicies[word[idx]].end())
                {
                    lastCharIndex = *itr;
                    
                    // last char
                    if(idx == (int)word.size() - 1)
                       count++; 
                }
                else
                    break;
            }
        }
        return count;
    }
};