class Solution {
private:
    static const int MAX = 1000 + 1, MOD = 1e9+7;
    long long memory[MAX][MAX];
    unordered_map<char, unordered_map<int, int>> charToIndecies;
    string target;
    int wordsLength, wordLength;
public:
    int numWays(vector<string>& words, string _target) 
    {
        wordsLength = words.size();
        wordLength = words[0].size();
        memset(memory, -1, sizeof(memory));
        target = _target;

        for(int i = 0 ; i < wordLength ; ++i)
            for(int j = 0 ; j < wordsLength ; ++j)
                ++charToIndecies[words[j][i]][i];
        
        int result{};
        for(auto[charIndex, freq] : charToIndecies[target[0]])
            result = (result + (long long)freq*countWays(1, charIndex)) % MOD;

        return result;
    }

    int countWays(int idx, int prevChoice)
    {
        if(idx >= target.size())
            return 1;

        if (prevChoice == wordLength ||
            wordLength - prevChoice < target.size() - idx)
            return 0;
        
        long long &ret = memory[idx][prevChoice];
        if(ret != -1)
            return ret;

        ret = 0;
        for(auto[charIndex, freq] : charToIndecies[target[idx]])
            if(charIndex > prevChoice)
                ret = (ret + (long long)freq*countWays(idx + 1, charIndex)) % MOD;
        
        return ret;
    }
};