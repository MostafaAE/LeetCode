class Solution {
public:
    /**
     * Approach:
     * - Every time a 0 is encountered, it must be moved before all the previous 1's. 
     * - So, for each 0, we add the number of 1's encountered so far to the result.
     * 
     * Complexity:
     * - Time Complexity: O(n), where `n` is the length of the string `s`.
     * - Space Complexity: O(1)
     */
    long long minimumSteps(string s) 
    {
        long long result{}, onesCount{};
        
        for(int i = 0 ; i < s.size() ; ++i)
        {
            if(s[i] == '1')
                ++onesCount;
            else
                result += onesCount;
        }
        
        return result;
    }
};