class Solution {
public:
    /**
     * Approach:
     * 1. Use two pointers, `itr1` for `str1` and `itr2` for `str2`, initialized to 0.
     * 2. Traverse `str1`:
     *    - Compare the current character of `str1` (`str1[itr1]`) with the current character of `str2` (`str2[itr2]`).
     *    - If they are equal, or if shifting `str1[itr1]` by 1 (cyclically within the alphabet) matches `str2[itr2]`, increment `itr2` to move to the next character in `str2`.
     *    - Always increment `itr1` to continue checking the next character in `str1`.
     * 3. If `itr2` reaches the size of `str2`, return `true` (all characters of `str2` matched in sequence within `str1`).
     * 4. If the loop ends without matching all of `str2`, return `false`.
     * 
     * Complexity:
     * Time Complexity: O(n)
     * - The traversal of `str1` is linear (where `n` is the size of `str1`).
     * Space Complexity: O(1)
     * - Constant space is used for pointers and variables.
     */
    bool canMakeSubsequence(string str1, string str2) 
    {
        int n = str1.size(), m = str2.size();
        if(m > n)
            return false;

        int itr1{}, itr2{};
        
        while(itr1 < n && itr2 < m)
        {
            int ch1 = str1[itr1] - 'a';
            int ch2 = str2[itr2] - 'a';
            int shiftedCh1 = (ch1 + 1) % 26;
            if(ch1 == ch2 || shiftedCh1 == ch2)
                ++itr2;
            ++itr1;
        }
        
        return itr2 == str2.size();
    }
};