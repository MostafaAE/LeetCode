class Solution {
public:
    string makeFancyString(string s) 
    {
        string result{};
        for(int i = 0 ; i < s.size() ; ++i)
        {
            if(i >=2 && s[i] == s[i-1] && s[i] == s[i-2])
                continue;
            
            result += s[i];
        }
        
        return result;
    }
};