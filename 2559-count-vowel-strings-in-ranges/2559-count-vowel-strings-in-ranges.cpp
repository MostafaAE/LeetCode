class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        int n = words.size(), q = queries.size();
        vector<int> prefix(n+2, 0);

        for(int i = 1 ; i <= n ; ++i)
        {
            prefix[i] = prefix[i-1] + isVowelString(words[i-1]);
        }

        vector<int> result(q);
        for(int i = 0 ; i < q ; ++i)
        {
            int l = queries[i][0], r = queries[i][1];
            result[i] = prefix[r+1] - prefix[l];
        }

        return result;
    }

    bool isVowelString(const string& str)
    {
        unordered_set<char> vowelSet({'a', 'e', 'i', 'o', 'u'});
        return vowelSet.count(str[0]) && vowelSet.count(str[str.size()-1]);
    }
};