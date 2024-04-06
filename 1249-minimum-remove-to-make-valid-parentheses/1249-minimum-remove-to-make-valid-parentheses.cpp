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
    string minRemoveToMakeValid(string s) 
    {
        stack<int> st;
        string res{};
        
        for(int i = 0 ; i < (int)s.size() ; i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
            {
                if(!st.empty())
                    st.pop();
                else
                    s[i] = '*';
            }
        }
        
        while(!st.empty())
        {
            s[st.top()] = '*';
            st.pop();
        }
        
        for(char c : s)
            if(c != '*')
                res += c;
        
        return res;
    }
};