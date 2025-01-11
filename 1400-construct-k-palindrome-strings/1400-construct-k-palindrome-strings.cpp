class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        if(s.size() < k)
            return false;
        
        vector<int> freq(26);
        int oddCount{};
        for(char c : s)
        {
            int freqIdx = c - 'a';
            ++freq[freqIdx];
            oddCount += freq[freqIdx]&1 ? 1 : -1;
        }

        return oddCount <= k;
    }
};