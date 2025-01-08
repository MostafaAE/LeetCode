class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        int n = words.size(), count{};

        for(int i = 0 ; i < n ; ++i)
            for(int j = i + 1 ; j < n ; ++j)
                count += isPrefixAndSuffix(words[i], words[j]);
            
        return count;
    }

    bool isPrefixAndSuffix(string str1, string str2)
    {
        int len1 = str1.size(), len2 = str2.size();

        if(len2 < len1)
            return false;
        
        for(int i = 0 ; i < len1 ; ++i)
            if(str1[i] != str2[i] || str1[len1-i-1] != str2[len2-i-1])
                return false;
        
        return true;
    }
};