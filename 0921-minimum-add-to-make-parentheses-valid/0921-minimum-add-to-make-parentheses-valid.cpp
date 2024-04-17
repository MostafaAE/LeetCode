class Solution {
public:
    /*
     * Approach
     * Count the number of open brackets and closed brackets that does not have a matching brackets.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    int minAddToMakeValid(string s) 
    {
        int openBrackets{}, closedBrackets{};
        
        for(char c : s)
        {
            if(c == '(')
                ++openBrackets;
            else if(openBrackets)
                --openBrackets;
            else
                ++closedBrackets;
        }
        
        return openBrackets + closedBrackets;
    }
};