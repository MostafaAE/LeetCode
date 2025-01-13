class Solution {
public:
    /**
     * Approach:
     * - Count the frequency of each character in the string.
     * - For each character:
     *   - If the frequency is odd, we can take 1 character.
     *   - If the frequency is even, we can take 2 characters.
     * 
     * Complexity:
     * - Time: O(n), where `n` is the length of the string.
     * - Space: O(1), as the frequency array is fixed to 26 characters.
     */
    int minimumLength(string s) 
    {
        vector<int> frequencies(26, 0);

        for(char c : s)
        {
            int idx = c - 'a';
            ++frequencies[idx];
        }

        int minLength{};
        for(int freq : frequencies)
        {
            if(freq&1) // odd
                minLength += 1;
            else if(freq > 0) // even & > 0
                minLength += 2;
        }

        return minLength;
    }
};