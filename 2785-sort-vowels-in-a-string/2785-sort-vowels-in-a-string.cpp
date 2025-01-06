class Solution {
public:
    string sortVowels(string s) 
    {
        int len = s.size();
        unordered_set<char> vowels{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        
        unordered_map<char, int> vowelToCount;
        for(int i = 0 ; i < len ; ++i)
            ++vowelToCount[s[i]];
        

        string result = s, sortedVowels = "AEIOUaeiou";
        int charIdx{};
        for(int i = 0 ; i < len ; ++i)
        {
            if(vowels.count(result[i]))
            {
                while(vowelToCount[sortedVowels[charIdx]] == 0)
                    ++charIdx;

                result[i] = sortedVowels[charIdx];
                --vowelToCount[sortedVowels[charIdx]];
            }
        }
        
        return result;
    }
};