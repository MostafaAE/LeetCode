class Solution {
public:
    int minimumPushes(string word) 
    {
        int n = word.size(), iterations =  n / 8;
        
        return (iterations + 1) * (n % 8) + 4 * iterations * (iterations + 1);
    }
};