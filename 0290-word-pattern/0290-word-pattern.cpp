class Solution {
public:
    /* 
    * Approach:
    * Complexity:
    * Time Complexity : O(n+m)
    * Space Complexity : O(n+m)
    */
    bool wordPattern(string pattern, string s) 
    {
        vector<string> words = split(s, ' ');
        
        unordered_map<char, string> cs;
        unordered_map<string, char> sc;
        
        if(words.size() != pattern.size())
            return false;
        
        for(int i = 0 ; i < (int)pattern.size() ; i++)
        {
            char ch = pattern[i];
            string word = words[i];
            
            if(cs.count(ch) && cs[ch] != word || sc.count(word) && sc[word] != ch)
                return false;
            
            cs[ch] = word;
            sc[word] = ch;
        }
        return true;
    }
    
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