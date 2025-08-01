class Solution {
public:
    int maxFreqSum(string s) 
    {
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
        vector<int> freq(26, 0);

        int maxVowelFreq = 0, maxConsonantFreq = 0;
        for(char c : s)
        {
            int idx = c - 'a';
            ++freq[idx];

            if(vowels.count(c))
                maxVowelFreq = max(maxVowelFreq, freq[idx]);
            else
                maxConsonantFreq = max(maxConsonantFreq, freq[idx]);
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};