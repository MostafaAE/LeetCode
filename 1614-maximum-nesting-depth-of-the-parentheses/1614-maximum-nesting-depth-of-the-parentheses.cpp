class Solution {
public:
    /*
     * Approach:
     * Utilize a stack to keep track of the maximum nested depth
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    int maxDepth(string s) 
    {
        int maxDepth{};
        stack<int> st;
        for(char c : s)
        {
            if(c == '(')
                st.push(0);
            else if(c == ')')
            {
                maxDepth = max(maxDepth, (int)st.size());
                st.pop();
            }
        }
        
        return maxDepth;
    }
};