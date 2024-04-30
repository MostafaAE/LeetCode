class Solution {
public:
    /*
    * Approach:
    * - Maintain a bitmask to represent the parity of characters in the substring.
    * - Iterate through each character in the word and update the bitmask accordingly.
    * - Increment the result by the count of wonderful substrings found so far (count of the other prefixes whose masks differ from the current prefix mask by at most one bit).
    *
    * Complexity:
    * - Time Complexity: O(n)
    * - Space Complexity: O(n)
    */
    long long wonderfulSubstrings(string word) 
    {
        unordered_map<unsigned int, int> bitmaskToCount;
        unsigned int bitmask{};
        long long result{};
        
        bitmaskToCount[0] = 1; // Initialize for handling the initial substring
        
        for(char ch : word)
        {
            unsigned int bitIdx = ch - 'a';
            bitmask ^= (1 << bitIdx); // Toggle the bit representing the current character
            
            result += bitmaskToCount[bitmask]; // Add the count of wonderful substrings with the current bitmask

            // Add the count of wonderful substrings with different bitmasks that differ by at most one bit
            for(int i = 0 ; i < 10 ; ++i)
                result += bitmaskToCount[bitmask^(1<<i)];
            
            ++bitmaskToCount[bitmask];
        }
        
        return result;
    }
};
