class Solution {
public:
    /* 
    * Approach:
    * store the frequency of each letter in each string
    * if the frequency of a character in t is less than the frequency of the same character in s then add the difference between the frequencies to the answer
    *
    *
    * Complexity:
    * Time Complexity : O(L)
    * Space Complexity : O(1)
    */
    int minSteps(string s, string t) {
        int n{(int)s.size()}, steps{};
        unordered_map<char, int> freq1, freq2;
        
        // O(L)
        for(int i = 0 ; i < n ; i++)
            freq1[s[i]]++, freq2[t[i]]++;
        
        for(auto&[ch, freq] : freq1)
            if(freq > freq2[ch])
                steps += freq - freq2[ch];
        
        return steps;
        
    }
};