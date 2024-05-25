class Solution {
public:
    /*
    * Approach:
    * - Use backtracking combined with memoization to explore all possible ways to split the string `s` into words found in `wordDict`.
    * - Create a set from `wordDict` for O(1) lookups.
    * - Use a helper function `split` to recursively build valid sentences.
    * - Use a hash map to store results of subproblems to avoid recomputation.
    *
    * Complexity:
    * - Time Complexity: O(2^N), where N is the length of the string `s`. The `2^N` term accounts for all possible substrings.
    * - Space Complexity: O(2^N)
    */
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string> result;
    
        unordered_set<string> wordDictionary(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memory;
            
        return split(0, s, wordDictionary, memory);
    }
    
    vector<string> split(int idx, string& s, unordered_set<string>& wordDict, unordered_map<int, vector<string>>& memory)
    {
        if(idx >= s.size())
            return {""};
        
        if(memory.count(idx))
            return memory[idx];
        
        string curWord = "";
        vector<string> result;
        for(int i = idx ; i < s.size() ; ++i)
        {
            curWord += s[i];
            if(wordDict.count(curWord))
            {
                auto strings = split(i + 1, s, wordDict, memory);
                for(string& word : strings)
                {
                    result.push_back(curWord + (word.empty() ? "" : " ") + word);
                }
            }
        }
        
        memory[idx] = result;
        return result;
    }
};