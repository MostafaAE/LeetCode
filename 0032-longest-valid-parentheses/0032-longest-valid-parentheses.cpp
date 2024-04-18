class Solution {
public:
    /*
     * Approach
     * Stack approach
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    int longestValidParentheses(string s) 
    {
        stack<int> st;
        int longest{}, opened{};
        st.push(0);
        
        for(char c : s)
        {
            if(c == '(')
            {
                st.push(0);
                ++opened;
            }
            else if(opened)
            {
                int child = st.top() + 2;
                st.pop();
                int parent = st.top() + child;
                st.pop();
                st.push(parent);
                longest = max(longest, parent);
                --opened;
            }
            else
            {
                st.push(0);
                opened = 0;
            }
        }
        
        return longest;
    }
};