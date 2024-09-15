class Solution {
public:
    /**
     * Approach:
     * - Use a bitmask to track the parity (even or odd count) of vowels ('a', 'e', 'i', 'o', 'u').
     * - Traverse the string, and whenever a vowel is found, toggle the corresponding bit in the bitmask.
     * - If the same bitmask has appeared before, it means the substring between the two indices has an even count of all vowels, so update the result.
     * - Use an unordered map `bitmaskToIdx` to store the first occurrence of each bitmask.
     * - Initialize the map with the bitmask `0` at index `-1` to account for substrings starting from the beginning of the string.
     * 
     * Complexity:
     * - Time Complexity: O(n), where `n` is the length of the string.
     * - Space Complexity: O(1), for storing the bitmask and O(1) for the map since there are only a fixed number of possible vowel bitmask combinations (2^5 = 32).
     */
    int findTheLongestSubstring(string s) 
    {
        int result{}, bitMask{};
        unordered_map<int, int> bitmaskToIdx;
        bitmaskToIdx[0] = -1;
        
        for(int i = 0 ; i < s.size() ; ++i)
        {
            if(isVowel(s[i]))
                bitMask ^= (1 << (s[i] - 'a'));
            
            if(bitmaskToIdx.count(bitMask))
                    result = max(result, i - bitmaskToIdx[bitMask]);
            else
                bitmaskToIdx[bitMask] = i;
        }
        
        return result;
    }
    
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
};