class Solution {
public:
    /*
     * Approach:
     * Keep track of the number of opened brackets
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    int maxDepth(string s) 
    {
        int maxDepth{}, openedBrackets{};
        for(char c : s)
        {
            if(c == '(')
                openedBrackets++;
            else if(c == ')')
            {
                maxDepth = max(maxDepth, openedBrackets);
                openedBrackets--;
            }
        }
        
        return maxDepth;
    }
};