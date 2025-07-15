class Solution {
public:
    bool isValid(string word) 
    {
        if(word.size() < 3)
            return false;

        bool hasVowel = false, hasConsonant = false;

        for(char c : word)
        {
            char lower = tolower(c);

            if(isLetter(lower))
            {
                if(isVowel(lower))
                    hasVowel = true;
                else
                    hasConsonant = true;
            }
            else if (!isDigit(lower))
            {
                // Invalid character
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
private:

    bool isVowel(char c) const
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u';
    }

    bool isDigit(char c) const 
    {
        return c >= '0' && c <= '9';
    }

    bool isLetter(char c) const 
    {
        return c >= 'a' && c <= 'z';
    }
};