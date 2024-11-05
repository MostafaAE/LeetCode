class Solution {
public:
    int minChanges(string s) 
    {
        int changes{};
        
        for(int i = 1 ; i < s.size() ; i+=2)
            if(s[i] != s[i-1])
                ++changes;
        
        return changes;
    }
};