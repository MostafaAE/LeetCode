class Solution {
public:
    /* 
    * Approach:
    * Iterate over the string with a variable-size sliding window
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) *There are only constant number of possible characters*
    */
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int maxLen{};
        
        for(int right = 0, left = 0 ; right < (int)s.size() ; right++)
        {
            while(set.count(s[right]))
                set.erase(s[left++]);
            
            set.insert(s[right]);
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};