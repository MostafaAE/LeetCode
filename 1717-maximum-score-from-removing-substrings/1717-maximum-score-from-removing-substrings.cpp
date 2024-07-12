class Solution {
public:
    /**
     * Approach:
     * - If x > y, first remove all "ab" pairs, then remove "ba" pairs.
     * - If y >= x, first remove all "ba" pairs, then remove "ab" pairs.
     * - The removePairs function uses a stack to efficiently find and remove pairs from the string.
     *   - Iterate through the string and use the stack to track potential start indices of pairs.
     *   - If a matching pair is found, update the result with the given score and mark the characters in the string as used by setting them to '.'.
     *
     * Complexity:
     * - Time Complexity: O(n)
     * - Space Complexity: O(n)
     */
    int maximumGain(string s, int x, int y) 
    {
        if(x > y)
            return removePairs(s, "ab", x) + removePairs(s, "ba", y);
        
        return removePairs(s, "ba", y) + removePairs(s, "ab", x);
    }
    
    int removePairs(string &s, string pair, int score)
    {
        int result{};
        stack<int> st;
        
        for(int i = 0 ; i < s.size() ; ++i)
        {
            if(!st.empty() && s[i] == pair[1] && s[st.top()] == pair[0])
            {
                result += score;
                s[i] = '.';
                s[st.top()] = '.';
                st.pop();
            }
            else if(s[i] != '.')
                st.push(i);
        }
        
        return result;
    }
    
};