class Solution {
public:
    string sortVowels(string s) 
    {
        int len = s.size();        
        unordered_map<char, int> vowelToCount;
        for(int i = 0 ; i < len ; ++i)
        {
            if(isVowel(s[i]))
                ++vowelToCount[s[i]];
        }
            
        string result = s, sortedVowels = "AEIOUaeiou";
        int charIdx{};
        for(int i = 0 ; i < len ; ++i)
        {
            if(isVowel(result[i]))
            {
                while(vowelToCount[sortedVowels[charIdx]] == 0)
                    ++charIdx;

                result[i] = sortedVowels[charIdx];
                --vowelToCount[sortedVowels[charIdx]];
            }
        }
        
        return result;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i' 
            || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
};