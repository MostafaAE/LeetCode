class Solution {
public:
    /* 
    * Approach:
    * Split the string s into words and then map each character in the pattern to its corresponding word and vice versa using two hash maps.
    *
    * Complexity:
    * Time Complexity : O(n+m)
    * Space Complexity : O(n+m)
    */
    bool wordPattern(string pattern, string s) 
    {
        vector<string> words = split(s, ' ');
        
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        if(words.size() != pattern.size())
            return false;
        
        for(int i = 0 ; i < (int)pattern.size() ; i++)
        {
            char ch = pattern[i];
            string word = words[i];
            
            if(charToWord.count(ch) && charToWord[ch] != word 
               || wordToChar.count(word) && wordToChar[word] != ch)
                return false;
            
            charToWord[ch] = word;
            wordToChar[word] = ch;
        }
        return true;
    }
    
    // O(m)
    vector<string> split(const string &s, char delim)
    {
        vector<string> result;
        stringstream ss(s);
        string word;
        while(getline(ss, word, delim))
            result.push_back(word);
        return result;  
    }
};