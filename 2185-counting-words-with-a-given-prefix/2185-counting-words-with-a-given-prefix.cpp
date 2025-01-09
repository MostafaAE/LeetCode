class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int count{};
        
        for(string& word : words)
            count += isPrefix(pref, word);
        
        return count;
    }

    bool isPrefix(string pref, string word)
    {
        if(pref > word)
            return false;

        for(int i = 0 ; i < pref.size() ; ++i)
            if(pref[i] != word[i])
                return false;

        return true;
    }
};