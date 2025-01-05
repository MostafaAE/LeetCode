class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        int n = s.size();

        int sum {};
        for(int i = 0 ; i < n ; ++i)
            sum = (sum + shifts[i]) % 26;
        
        string shifted(n, ' ');
        for(int i = 0 ; i < n ; ++i)
        {
            int charIdx = s[i] - 'a';
            int shiftedCharIdx = (charIdx + sum) % 26;
            shifted[i] = 'a' + shiftedCharIdx;
        
            sum = ((sum - shifts[i]) % 26 + 26) % 26;
        }

        return shifted;
    }
};
