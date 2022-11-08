class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    string makeGood(string s) 
    {
        stack<char> st;
        string result{};
        
        for(int i = 0 ; i < (int)s.size() ; i++)
        {
            if(!st.empty() && abs(st.top() - s[i]) == 32)
                st.pop();
            else
                st.push(s[i]);
        }
        
        while(!st.empty())
            result = st.top() + result, st.pop();
        
        return result;
        
    }
};