class Solution {
public:
    string reverseWords(string s) 
    {
        string result{};
        stringstream ss(s);
        
        string word{};
        while(getline(ss, word, ' '))
        {
            if(!result.empty())
                result += " ";
            reverse(word.begin(), word.end());
            result += word;
        }
        
        return result;
    }
};