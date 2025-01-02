class Solution {
public:
    string stringHash(string s, int k) 
    {
        int  n = s.size();
        string result{}, curSubstring{};
        
        for(int i = 0 ; i < n ; ++i)
        {
            curSubstring += s[i];

            if(curSubstring.size() == k)
            {
                result += getHashed(curSubstring);
                curSubstring = "";
            }
        }

        return result;
    }

    char getHashed(const string& s)
    {
        int hashedValue{};
        for(char c : s)
            hashedValue = (hashedValue + (c-'a')) % 26;
        
        return hashedValue + 'a';
    }
};