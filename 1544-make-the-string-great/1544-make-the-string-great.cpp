class Solution {
public:
    /*
     * Approach:
     * Stack approach.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    string makeGood(string s) 
    {
        string res{};
        stack<char> st;
        
        for(char c : s)
        {
            if(!st.empty() && c != st.top() && tolower(c) == tolower(st.top()))
                st.pop();
            else
                st.push(c);
        }
        
        while(!st.empty())
            res = st.top() + res, st.pop();
        
        return res;
    }
};