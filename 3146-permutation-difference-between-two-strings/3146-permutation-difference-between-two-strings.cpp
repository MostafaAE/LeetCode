class Solution {
public:
    int findPermutationDifference(string s, string t) 
    {
        int result{};
        unordered_map<int, int> charToIndex;

        for(int i = 0 ; i < s.size() ; ++i)
            charToIndex[s[i]] = i;

        for(int i = 0 ; i < t.size() ; ++i)
            result += abs(i-charToIndex[t[i]]);

        return result;
    }
};