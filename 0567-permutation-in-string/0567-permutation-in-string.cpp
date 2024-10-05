class Solution {
public:
    /**
     * Approach:
     * - Use a sliding window technique to check if any substring of `s2` is a permutation of `s1`.
     * - First, calculate the frequency of characters in `s1` and the first window of size `s1` in `s2`.
     * - Slide the window over `s2`, updating the character frequencies by removing the frequency of the outgoing character and adding the frequency of the incoming character.
     * - After each update, compare the frequency maps of `s1` and the current window in `s2` to check if they are the same.
     * 
     * Complexity:
     * - Time Complexity: O(n), where `n` is the size of `s2`. We perform a single pass over `s2` with a window of size `s1`, and checking frequency maps takes constant time if the map size is fixed (26 letters for lowercase).
     * - Space Complexity: O(1), as the frequency maps store only the character counts of the alphabet (fixed size).
     */
    bool checkInclusion(string s1, string s2) 
    {
        if (s1.size() > s2.size())
            return false;
        
        int len1 = s1.size(), len2 = s2.size();
        
        unordered_map<int, int> s1Freq, s2Freq;
        
        // Initialize the frequency maps for s1 and the first window in s2
        for (int i = 0; i < len1; ++i)
        {
            ++s1Freq[s1[i]];
            ++s2Freq[s2[i]];
        }
        
        // Check if the first window matches
        if (isSameFreq(s1Freq, s2Freq))
            return true;
        
        // Slide the window over s2
        int end = len1;
        while (end < len2)
        {
            --s2Freq[s2[end - len1]];  // Remove the character going out of the window
            ++s2Freq[s2[end]];         // Add the character coming into the window
            ++end;
            
            // Check if the updated window matches
            if (isSameFreq(s1Freq, s2Freq))
                return true;
        }
        
        return false;
    }
    
    // Helper function to compare two frequency maps
    bool isSameFreq(unordered_map<int, int>& s1Freq, unordered_map<int, int>& s2Freq)
    {
        for (auto [ch, freq] : s1Freq)
            if (s2Freq[ch] != freq)
                return false;
      
        return true;
    }
};
