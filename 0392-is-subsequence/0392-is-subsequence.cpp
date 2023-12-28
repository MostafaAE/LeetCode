class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int sLen{(int)s.size()}, tLen{(int)t.size()}, matched{};

        for(int idx1 = 0, idx2 = 0 ; idx2 < tLen ; idx2++)
        {
            if(s[idx1] == t[idx2])
            {
                idx1++;
                matched++;
            }
        }
        return matched == sLen;
    }
};