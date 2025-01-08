class Solution {
public:
    vector<string> stringSequence(string target) 
    {
        vector<string> result;
        string cur{};

        for(char c : target)
        {
            for(char typed = 'a' ; typed <= c ; ++typed)
                result.push_back(cur+typed);
                
            cur += c;
        }

        return result;
    }
};