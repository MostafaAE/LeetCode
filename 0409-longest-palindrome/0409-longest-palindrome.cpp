class Solution {
public:
    /*
     * Approach:
     * Utilize a hashmap to count the frequency of each character in the string, while keeping track of the odd characters count
     * In the end, if there is at least one character with an odd frequency, return the length of the string minus the oddCount plus 1,
     * otherwise, return the length of the string.
     *
     * Complexity:
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    int longestPalindrome(string s) 
    {
        int oddCount{};
        unordered_map<char, int> charToCount;
        
        for(char c : s)
        {
            if(++charToCount[c] & 1)
                ++oddCount;
            else
                --oddCount;
        }

        if(oddCount)
            return s.size() - oddCount + 1;
        return s.size();
    }
};