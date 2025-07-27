class Solution {
public:
    int reverseDegree(string s) 
    {
        int n = s.size(), sum = 0;

        for(int i = 0 ; i < n ; ++i)
        {
            int idx = i + 1;
            int reversedIdx = 26 - (s[i] - 'a');
            sum += (idx * reversedIdx);
        }

        return sum;
    }
};