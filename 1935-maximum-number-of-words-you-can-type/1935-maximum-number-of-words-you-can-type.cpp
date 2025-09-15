class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) 
    {
        stringstream ss(text);
        string word;
        unordered_set<char> brokenLettersHashset(brokenLetters.begin(), brokenLetters.end());

        int count = 0;
        while(getline(ss, word, ' '))
        {
            count += canBeTyped(word, brokenLettersHashset);
        }

        return count;
    }

    bool canBeTyped(const string& word, unordered_set<char>& brokenLettersHashset)
    {
        for(char c : word)
        {
            if(brokenLettersHashset.count(c))
                return false;
        }

        return true;
    }
};