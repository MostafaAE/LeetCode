class Solution {
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        int n = s.size(), m = spaces.size(), spaceIdx{};
        string result(m+n,' ');
        
        for(int i = 0 ; i < n ; ++i)
        {
            if(spaceIdx < m && i == spaces[spaceIdx])
                ++spaceIdx;
            result[i+spaceIdx] = s[i];
        }
        
        return result;
    }
};