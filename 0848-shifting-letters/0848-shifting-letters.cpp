class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        int n = s.size();
        vector<int> diffArray(n, 0);

        diffArray[n-1] = shifts[n-1];
        for(int i = n-2 ; i >= 0 ; --i)
            diffArray[i] = (shifts[i] + diffArray[i+1]) % 26;
        
        string shifted(n, ' ');
        for(int i = 0 ; i < n ; ++i)
        {
            int charIdx = s[i] - 'a';
            int shiftedCharIdx = (charIdx + diffArray[i]) % 26;
            shifted[i] = 'a' + shiftedCharIdx;
        }

        return shifted;
    }
};
