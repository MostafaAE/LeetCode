class Solution {
public:
    /*
     * Approach
     * Count bulls (correct position digits) by comparing characters in the same position in secret and guess.
     * For each out-of-position digit, track their frequency in both secret and guess using arrays.
     * Calculate cows (out-of-position but existing digits) by finding the minimum frequency between the two arrays.
     *
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    string getHint(string secret, string guess) 
    {
        vector<int> secretFreq(10, 0), guessFreq(10, 0);
        int bulls{}, cows{};
        
        for(int i = 0 ; i < (int)guess.size() ; i++)
        {
            if(secret[i] == guess[i])
                ++bulls;
            else
            {
                secretFreq[secret[i] - '0']++;
                guessFreq[guess[i] - '0']++;
            }
        }
        
        for(int i = 0 ; i < (int)secretFreq.size() ; i++)
            cows += min(secretFreq[i], guessFreq[i]);
    
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};